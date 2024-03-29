using namespace std;
int main(){}
#include<cstdio>
#include<cctype>
#include<cstring>
const long long mod=(long long)1e9+9;

struct Matrix{
	int elecnt;
	long long data[55][55];
	long long _OverFlowTemp_;
template<typename Type1,typename Type2>	
	long long & operator () (Type1 i,Type2 j){
		if(i<0 || j<0 || i>=elecnt || j>=elecnt)return _OverFlowTemp_;
		else return data[i][j];
	}
	Matrix friend operator * (Matrix a,Matrix b){
		Matrix ret;ret.zero();ret.elecnt=a.elecnt;
		int i,j,k;
		for(i=0;i<a.elecnt;i++){
			for(j=0;j<a.elecnt;j++){
				for(k=0;k<a.elecnt;k++){
					ret(i,j)+=a(i,k)*b(k,j);
					ret(i,j)%=mod;
				}
			}
		}
		return ret;
	}
	void zero(){
		memset(this,0,sizeof(Matrix));
	}
	void one(){
		memset(data,0,sizeof(data));
		int i;
		for(i=0;i<elecnt;i++){
			data[i][i]=1;
		}
	}
};


long long fastpower(long long base,long long pow){
	long long ans=1;
	while (pow){
		if(pow&1){
			ans=ans*base%mod;
		}
		base=base*base%mod;
		pow>>=1;
	}
	return ans;
}
Matrix fastpower(Matrix base,int pow){
	Matrix ans;ans.elecnt=base.elecnt;
	ans.one();
	while(pow){
		if(pow &1){
			ans=ans*base;
		}
		base=base*base;
		pow>>=1;
	}
	int i,j;
	return ans;
}
void modread(long long &a){
	char t;
	while(!isdigit(t=getchar()));
	a=t-'0';
	while( isdigit(t=getchar())){
		a*=10;a+=t-'0';
		a%=mod-1;
	}
}
long long inline getdiv(long long num){
	return fastpower(num,mod-2);
}

struct _Main{
	template<typename Type>
		void read(Type &a){
			char t;
			while(!isdigit(t=getchar()));
			a=t-'0';
			while( isdigit(t=getchar())){
				a*=10;a+=t-'0';
			}
		}
int n,m;
int getidx(int x,int y){
	if(x<=0 || x>n || y<=0 || y>m){
		return -1;
	}else{
		return (x-1)*m+(y-1);
	}
}
long long org[55][55];
Matrix beg,rate,ans;
long long a[5],b[5];
_Main(){
	int i,j,k;int xi,yi,xj,yj,val;long long t;
	int ccnt,qcnt;
	read(n);read(m);read(ccnt);read(qcnt);
	for(i=0;i<ccnt;i++){
		read(xi);read(yi);read(xj);read(yj);read(val);
		for(j=xi;j<=xj;j++){
			for(k=yi;k<=yj;k++){
				org[j][k]+=val;
			}
		}
	}
	ans.elecnt=rate.elecnt=beg.elecnt=n*m;
	for(i=n;i>0;i--){
		for(j=m;j>0;j--){
			beg(0,getidx(i,j))=org[i][j]%mod;
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			for(k=0;k<5;k++){
				read(a[k]);read(b[k]);
			}
			rate(getidx(i,j),getidx(i,j))=(a[0]*getdiv(b[0])+1)%mod;
			rate(getidx(i,j),getidx(i-1,j))=a[1]*getdiv(b[1])%mod;
			rate(getidx(i,j),getidx(i+1,j))=a[2]*getdiv(b[2])%mod;
			rate(getidx(i,j),getidx(i,j-1))=a[3]*getdiv(b[3])%mod;
			rate(getidx(i,j),getidx(i,j+1))=a[4]*getdiv(b[4])%mod;			
		}
	}
	for(i=1;i<=qcnt;i++){
		modread(t);
		ans=beg*fastpower(rate,t);
		for(j=0;j<ans.elecnt;j++){
			printf("%lld ",(ans(0,j)%mod+mod)%mod);
		}
		printf("\n");
	}
	fclose(stdout);
}	
	
	
}virus;

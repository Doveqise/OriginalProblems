using namespace std;
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<string>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<fstream>
#include <vector>
//#include "splay.hpp"
typedef long long lld;
struct _Main{
//////////////
string dataName = "data";
string stdName = "timber";
string bruteName = "brute";
bool make_data = 1;
bool run_ans = true;

lld srand_seed = 0;

int beg = 0
,   end = 20
,   exbeg = 0
,   exend = 3
;

bool check_brute = 0;
bool check_out_pause = true;
bool loop_check = 0;
bool loop_count = true;
bool time_count = true;
bool brute_time_count = true;

//////////////

//Splay<400005>leaf, id, void_id;
int id[500050];
void make(){
	int I;
	int i,j,k;
	for(I=beg;I<end;I++){
		outfile=dataName+to_string(I)+".in";
		cerr<<"Make "<<outfile<<endl;
		ofstream cout(outfile.c_str());
		int cnt;
		int m;		
		int n = 500000;
		for (int i = 1; i <= n; i++) {
			id[i] = i;
		}
		if (I & 1) shuffle(id + 1, n);
		
		if (I >> 1 == 0) { //bitrand(1,5000)棵 
			cnt = bit_rand(1, 5000);
			m = n - cnt;
			cout << n << sp << m << endl;
			randforest(1, n, cnt, cout);
		} else 
		if (I >> 1 == 1) {//lrand(1,50W)棵 
			cnt = lrand(1, 500000);
			m = n - cnt;
			cout << n << sp << m << endl;
			randforest(1, n, cnt, cout);
		} else
		if (I >> 1 == 2) { // 1条40W链 + 10W随机边 
			m = n - 1;
			cout << n << sp << m << endl;
			mchain(1, 2, 4e5, cout);
			for (int i = 4e5 + 1; i <= n; i++) {
				add(i, lrand(1, i - 1), cout);
			}
		} else if (I >> 1 == 3) {//一棵随机树 
			m = n - 1;
			cout << n << sp << m << endl;
			mtree(1, 2, n, cout);
		} else if (I >> 1 == 4) {//700棵随机树 
			cnt = 700;
			m = n - cnt;
			cout << n << sp << m << endl;
			randforest(1, n, cnt, cout);
		} else if (I >> 1 == 5) {// 4.5W * 10个的菊花 + 5W随机边
			cnt = 10; m = n - cnt;
			cout << n << sp << m << endl; 
			for (int i = 1; i <= 10; i++) {
				mflower((i - 1) * 4.5e4 + 1, (i - 1) * 4.5e4 + 2, i * 4.5e4, cout);
			}
			for (int i = 4.5e5 + 1; i <= n; i++) {
				add(i, lrand(1, i - 1), cout);
			}
			
		} else if (I >> 1 == 6) {// 4个 4W+2W+4W哑铃   + 10w随机边 
			cnt = 4;
			m = n - cnt;
			cout << n << sp << m << endl;
			for (int i = 1; i <= 4; i++) {
				int base = (i - 1) * 1e5;
				int l = 1, r = 2e4;
				mchain(base + 1, base + 2, base + 2e4, cout);
				mflower(base + 1, base + 2e4 + 1, base + 6e4, cout);
				mflower(base + 2e4, base + 6e4 + 1, base + 1e5, cout);
			}
			for (int i = 4e5 + 1; i <= n; i++) {
				add(i, lrand(1, i - 1), cout);
			}
		} else if (I >> 1 == 7) {//4个10W毛毛虫 + 10w随机边 
			cnt = 4;
			m = n - cnt;
			cout << n << sp << m << endl;			
			for (int i = 1; i <= 4; i++) {
				mworm(((i - 1) * 1e5) + 1, ((i - 1) * 1e5) + 2, i * 1e5, cout);
			}
			for (int i = 4e5 + 1; i <= n; i++) {
				add(i, lrand(1, i - 1), cout);
			}
		} else if (I >> 1 == 8) {//1个10W毛毛虫，1个10W菊花，1个10W随机树,10W点1W树，10W 随机边 
			cnt = 1e4 + 3;
			m = n - cnt;
			cout << n << sp << m << endl;			
			mworm(1, 2, 1e5, cout);
			mflower(1e5 + 1, 1e5 + 2, 2e5, cout);
			mtree(2e5 + 1, 2e5 + 2, 3e5, cout);
			randforest(3e5 + 1, 4e5, 1e4, cout);
			for (int i = 4e5 + 1; i <= n; i++) {
				add(i, lrand(1, i - 1), cout);
			}
		} else if (I >> 1 == 9) {//40W的菊花二叉树+10W随机边 
			cnt = 1;
			m = n - 1;
			cout << n << sp << m << endl;
			mbtree(1, 2, 2e5, cout);
			mflower(1, 2e5 + 1, 4e5, cout);
			for (int i = 4e5 + 1; i <= n; i++) {
				add(i, lrand(1, i - 1), cout);
			}
		}


		EndFor1:
		cout.close();
	}
	

	
	for(I=exbeg;I<exend;I++){
		outfile=dataName+"_ex"+to_string(I)+".in";
		cerr<<"Make "<<outfile<<endl;
		ofstream cout(outfile.c_str());
		if (I == 0) {
			cout << 1 << sp << 0 << endl;
		} else 
		if (I == 1) {
			cout << 2 << sp << 1 << endl << 1 << sp << 2 << endl;
		} else 
		if (I == 2) {
			int n = 5e5, cnt = 4.5e5;
			int m = n - cnt;
			cout << n << sp << m << endl;
			for (int i = 1; i <= (int)1.5e5; i++) {
				add(i * 3, i * 3 - 2, cout);
				add(i * 3 - 2, i * 3 - 1, cout);
			}
			for (int i = 4.5e5 + 1; i <= n; i++) {
				add(i, lrand(1, i - 1), cout);
			}
		}
        
		EndFor2:
		cout.close();
	}	
	
	
}
int Qcnt;


const int 
	NXT = 1, 
	DST = 0
;



void run(){
	int I;
    float a, b;
	for(I=beg;I<end;I++){
		cmd= stdName + ".exe > "+dataName+to_string(I)+".out < "+dataName+to_string(I)+".in";
		cerr<<"Run: "<<cmd<<endl;
		a = clock();
		system(cmd.c_str());
		b = clock();
		if (time_count) {
		    cerr<<stdName + " uses "<<b - a<<"ms"<<endl;
		}
		
		if (check_brute) {
    		cmd= bruteName + ".exe > brute"+to_string(I)+".out < "+dataName+to_string(I)+".in";
    		cerr<<"Run: "<<cmd<<endl;
            a = clock();
            system(cmd.c_str());
    		b = clock();
    		if (brute_time_count) {
    		    cerr<<bruteName + " uses "<<b - a<<"ms"<<endl;
    		}    		
    		cmd="fc brute"+to_string(I)+".out "+dataName+to_string(I)+".out";
    		if(system(cmd.c_str()) && check_out_pause){
    			system("pause");
    		}
	    }
	}
	
	for(I=exbeg;I<exend;I++){
		cmd= stdName + ".exe > "+dataName+"_ex"+to_string(I)+".out < "+dataName+"_ex"+to_string(I)+".in";
		cerr<<"Run: "<<cmd<<endl;
		a = clock();
		system(cmd.c_str());
		b = clock();
		if (time_count) {
		    cerr<<stdName + " uses "<<b - a<<"ms"<<endl<<endl;
		}
		
		if (check_brute) {	
    		cmd= bruteName + ".exe > brute_ex"+to_string(I)+".out < "+dataName+"_ex"+to_string(I)+".in";
    		cerr<<"Run: "<<cmd<<endl;
            a = clock();
            system(cmd.c_str());
    		b = clock();
    		if (brute_time_count) {
    		    cerr<<bruteName + " uses "<<b - a<<"ms"<<endl;
    		}    
    		cmd="fc brute_ex"+to_string(I)+".out "+dataName+"_ex"+to_string(I)+".out";
    		if(system(cmd.c_str()) && check_out_pause){
    			system("pause");
    		}
		}
	}
	
}


_Main(){
    int loopCnt = 0;
	getprime();
	if (srand_seed == 0) {
		srand_seed = time(0);
	}
	cerr<<"seed = "<<srand_seed << endl;
	srand(srand_seed);
	if (!loop_check){
    	if (make_data) {
    	    make();
    	}
        if (run_ans) {
            run();	
        }
	} else {
	    while (1) {
	        loopCnt++;
	        if (loop_count) {
	           cerr<<"loop "<<loopCnt<<":"<<endl; 
	        }
	        if (make_data) {
	            make();
	        }
	        if (run_ans) {
	            run();
	            cerr<<endl;
	        }
	    }
	}
	


}	
int mksq(int root, int l, int r, ostream &cout) {
	if (r - l + 1 < 200000 * 2 + 10) {
		mchain(root, l, r, cout);
		return r;
	}
	int mid = l + r >> 1;
	int ls = l + 200000 - 1, rs = mid + 200000 - 1;
	mchain(root, l, ls, cout);
	mchain(root, mid, rs, cout);
	int ret = mksq(ls, ls + 1, mid - 1, cout);
	mksq(rs, rs + 1, r, cout);
	return ret;
}
void mtree(int beg, int now, int end, ostream &cout) {
	for(int i = now; i <= end; i++) {
		add(i, lrand(beg, i - 1), cout);
	}
}
void mchain(int tail, int now, int end, ostream &cout) {
	for(int i = now; i <= end; i++) {
		add(i, tail, cout);
		tail = i;
	}
}
void mflower(int core, int now, int end, ostream &cout) {
	for (int i = now; i <= end; i++) {
		add(i, core, cout);
	}
}
void mbtree(int root, int now, int end, ostream &cout) {
	if (now < end) {
		int mid = now + end >> 1;
		add(root, now, cout);
		add(root, mid + 1, cout);
		mbtree(now, now + 1, mid, cout);
		mbtree(mid + 1, mid + 2, end, cout);
	} else if (now == end) {
		add(root, now, cout);
	}
}
void mworm(int root, int now, int end, ostream &cout) {
	while (now <= end) {
		add(root, now++, cout);
		if (now <= end) {
			add(root, now++, cout);
			root = now - 1;
		}
	}
}
void add(int a, int b, ostream &cout) { //要求编号较大的点是第一次连边 
	if (rand() & 1) swap(a, b);
	cout << id[a] << sp << id[b] << endl;
}

int gap[500005];
int fa[500005];
int getfa(int a) {
	return fa[a] ? fa[a] = getfa(fa[a]) : a;
}
void setfa(int a, int b) {
	fa[a] = b;
}
void randforest(int beg, int end, int cnt, ostream &cout) {
	memset(gap + beg, 0, (end - beg + 1) * sizeof(int));
	for (int i = beg ; i < beg + cnt - 1; i++) {
		gap[i] = 1;
	}
	shuffle(gap + beg, end - beg + 1);
	gap[end + 1] = 1; 
	int head = beg;
	for (int i = beg; i <= end + 1; i++) {
		if (gap[i]) {
			if (i > head) {
				mtree(head, head + 1, i, cout);
			}
			head = i;
		}
	}
}	
	
	
char out_tmp[100000];
int name[100010];	
struct Edge{
	int a,b,c;
}edge[200010];	
/*
int eidx;
void add(int a, int b, int c) {
    edge[eidx++] = (Edge) {a, b, c};
}
*/
	int lim,alph;
template<typename Type>
	void shuffle(Type *beg,int size){
		int i;
		for(i=1;i<size;i++){
			swap(beg[lrand()%(i+1)],beg[i]);
		}
	}
int prime[2000000];
int primecnt;bool vis[10000005];
void getprime(){
	int i,j;
	for(i=2;i<=10000000;i++){
		if(!vis[i]){
			prime[primecnt++]=i;
		}
		for(j=0;j<primecnt && i*prime[j] <=10000000;j++){
			vis[i*prime[j]]=true;
			if(i%prime[j]==0)break;
		}
	}
	
}
	
int lrand(){
	return (rand()<<16) | (rand()<<1) ^rand();	
}
long long llrand(){
	return (long long)((long long)lrand()<<32)|((long long )lrand()<<1)^rand();
}
string outfile,cmd,infile;
string to_string(int a){
	stringstream os;string ans;
	os<<a;
	os>>ans;
	return ans;
}
int randsym(){
	return (rand()&1)?-1:1;
}

string arr[100010];
void shuffleedge(Edge *beg,int n,int m,bool directed = false){
	int i;
	for(i=1;i<=n;i++){
		name[i]=i;
	}
	shuffle(name+1,n);
	shuffle(beg,m);
    if (!directed) {
    	for(i=0;i<m;i++){
    		if(rand()&1)swap(beg[i].a,beg[i].b);
    		beg[i].a=name[beg[i].a];
    		beg[i].b=name[beg[i].b];
    	}
    }
}
void inline add (int a,int b,int c,int &idx){
	edge[idx].a=a;
	edge[idx].b=b;
	edge[idx].c=c;
	idx++;
}
int arr1[400010],arr2[400010];
char type[4000010];
int mod=1e5+1;


lld lrand(lld min, lld max) {
    return llrand(min, max);
}
lld llrand(lld min, lld max) {
    return llrand() % (max - min + 1) + min;
}	
lld bit_rand() {
    return llrand() & ((1u << lrand(0, 63)) - 1);
} 
lld bit_rand(lld min, lld max) {
    return bit_rand() % (max - min + 1) + min;
}
	
string charset = "0123456789qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM~!@#$%^&*()_+\"`-={}|[]\\:;’<>?,./ ";	

char randchar(int l, int r) {
    return charset[lrand(l, r)];
}
char randchar() {
    return randchar(0, 32 + 26 * 2 + 10 - 1);
}
int judge_type(char a) {
    if (isdigit(a)) {
        return DIGIT;
    }
    if (islower(a)){
        return LOWER;
    }
    if (isupper(a)){
        return UPPER;
    }    
    return SYMBOL;
}
char randchar(int type) {
    char t;
    do {
        t = randchar();
    } while((judge_type(t) & type) == 0);
    return t;
}

void randRange(int beg, int end, int &l_, int &r_) {
    l_ = lrand() % (end - beg + 1);
    r_ = lrand() % (end - beg + 1 - l_);
    l_ += beg;
    r_ += l_;
}

void bit_randRange(int beg, int end, int &l_, int &r_) {
    l_ = bit_rand() % (end - beg + 1);
    r_ = bit_rand() % (end - beg + 1 - l_);
    l_ += beg;
    r_ += l_;
}
const int 
    LOWER = 1,
    UPPER = 2,
    ALPHA = 3,
    DIGIT = 4,
    SYMBOL = 8,
    ALL = 15
;
const string sp = " ";
}Maker;

/*
//#include<bits/stdc++.h>
*/

int main(){}

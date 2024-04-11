#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=1e9+7;
int f[102][3]={{1,2,0},{3,3,1},{4,4,2},{5,6,1},{7,8,2},{9,12,0},{13,14,1},{15,18,2},{19,26,0},{27,38,1},{39,39,2},{40,56,0},{57,57,2},{58,80,1},{81,84,2},{85,119,0},{120,120,2},{121,173,1},{174,178,2},{179,254,0},{255,259,2},{260,362,1},{363,381,2},{382,536,0},{537,543,2},{544,779,1},{780,804,2},{805,1145,0},{1146,1168,2},{1169,1631,1},{1632,1717,2},{1718,2414,0},{2415,2446,2},{2447,3506,1},{3507,3621,2},{3622,5153,0},{5154,5259,2},{5260,7340,1},{7341,7729,2},{7730,10865,0},{10866,11010,2},{11011,15779,1},{15780,16297,2},{16298,23189,0},{23190,23668,2},{23669,33032,1},{33033,34783,2},{34784,48893,0},{48894,49548,2},{49549,71006,1},{71007,73339,2},{73340,104351,0},{104352,106509,2},{106510,148646,1},{148647,156526,2},{156527,220019,0},{220020,222969,2},{222970,319529,1},{319530,330028,2},{330029,469580,0},{469581,479293,2},{479294,668909,1},{668910,704370,2},{704371,990086,0},{990087,1003363,2},{1003364,1437881,1},{1437882,1485129,2},{1485130,2113112,0},{2113113,2156821,2},{2156822,3010091,1},{3010092,3169668,2},{3169669,4455389,0},{4455390,4515136,2},{4515137,6470465,1},{6470466,6683083,2},{6683084,9509006,0},{9509007,9705697,2},{9705698,13545410,1},{13545411,14263509,2},{14263510,20049251,0},{20049252,20318115,2},{20318116,29117093,1},{29117094,30073876,2},{30073877,42790529,0},{42790530,43675639,2},{43675640,60954347,1},{60954348,64185793,2},{64185794,90221630,0},{90221631,91431520,2},{91431521,131026919,1},{131026920,135332445,2},{135332446,192557381,0},{192557382,196540378,2},{196540379,274294562,1},{274294563,288836071,2},{288836072,405997337,0},{405997338,411441843,2},{411441844,589621136,1},{589621137,608996005,2},{608996006,866508215,0},{866508216,884431704,2},{884431705,1000000000,1}};
int n,p,ans;
int myp(int x,int t){
	int ans=1;
	for(;t;t>>=1,x=(ll)x*x%M)if(t&1)ans=(ll)ans*x%M;
	return ans;
}
int g[4];
void XOR(int *f,int x){
	for(int b=2,i=1;b<=4;b<<=1,i<<=1)
		for(int j=0;j<4;j+=b)
			for(int k=0;k<i;k++){
				int A=f[j+k],B=f[i+j+k];
				f[j+k]=(ll)(A+B)*x%M;
				f[i+j+k]=(ll)(A-B+M)*x%M;
			}
}
int main(){
	scanf("%d%d",&n,&p);
	for(int i=0;i<102;i++){
		if(p<f[i][0])break;
		f[i][1]=min(f[i][1],p);
		int l=p-f[i][1],r=p-f[i][0];
		(g[f[i][2]]+=(ll)(l+r)*(r-l+1)/2%M)%=M;
	}
	XOR(g,1);
	for(int i=0;i<4;i++)g[i]=myp(g[i],n);
	XOR(g,(M+1)/2);
	for(int i=1;i<4;i++)(ans+=g[i])%=M;
	printf("%d",ans);
}
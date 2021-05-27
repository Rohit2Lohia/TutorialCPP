#include<bits/stdc++.h>
using namespace std;
#define MAX 100

class Imp_prop
{
public:

	vector <pair<int, int>> adj[1000];
	bool visited[1000];
	int x,sum;

//	void dfs(int s) {
//		 visited[s] = true;
//		 for(int i=0; i<adj[s].size(); ++i){
//		  if(visited[adj[s][i].first] == false){
//				sum+=x_val(x, adj[s][i].second);
//				dfs(adj[s][i].first);
//		  }
//		 }
//	}

	void initialize(int n) {
		 for(int i=0; i<n; ++i)
		  visited[i] = false;
	}

	bool chPal(string t){
		int l=t.length();
		transform(t.begin(), t.end(), t.begin(), ::tolower);
		cout<<t<< ' ';
		for(int i=0; i<l; i++,l--){
			if(t[i]!=t[l-1])
				return false;
		}
		return true;
	}

	int check(string s){
		/// 	This function will check for the no. of palindrome in the sentence
		int res=0, cnt=0;
		string t="";
		s+=" ";
		for(int i=0; i<s.length(); i++){
			char c = s.at(i);
			if(c != ' '){
				t+=c;
			}
			else{
				if(chPal(t))
					cnt++;
				t="";
			}
		}
		return cnt;
	}

	int opr(string s1, string s2){
		int arr[s1.length()+1][s2.length()+1];
		for(int i=0; i<=s1.length(); i++){
			for(int j=0; j<=s2.length(); j++){
				if(i==0) arr[i][j]=i;
				else if(j==0) arr[i][j]=j;
				else if(s1[i]==s2[j]) arr[i][j]=arr[i-1][j-1];
				else arr[i][j] = 1 + min(arr[i][j-1], min(arr[i-1][j],arr[i-1][j-1]));
			}
		}

		return arr[s1.length()][s2.length()];
	}

	void factors(int n) {
		vector<int> f;
		for (int x = 2; x*x <= n; x++) {
			while (n%x == 0) {
				f.push_back(x);
				n /= x;
			}
		}
		if (n > 1) f.push_back(n);
		for(auto i:f)
			cout<<i<< ' ';
	}
	int gcd(int a, int b){
		if(b==0)
			return a;
		gcd (b, a%b);
	}
};

int fib[MAX];

class Solution
{
public:
	void _initialize() {
		for (int i=0; i<MAX; i++)
			fib[i]=-1;
	}

	int fibbo(int t) {
		if( fib[t]==-1 ){
			if(t<=1)
				fib[t]=t;
			else
				fib[t] =fibbo(t-1)+fibbo(t-2);
		}
		return fib[t];
	}

	int fibob(int t){
		int arr[t+1];
		arr[0]=0;
		arr[1]=1;
		for(int i=2; i<=t; i++){
			arr[i]=arr[i-1]+arr[i-2];
		}
		return arr[t];
	}

	int recufib(int t){
		if(t<=1)
			return t;
		else
			return recufib(t-1)+recufib(t-2);
	}

	int combi135(int t){
		if(t<0)
			return 0;
		if(t==0)
			return 1;
		if(t==1)
			return 1;
		if(fib[t] != -1)
			return fib[t];

		return fib[t]=combi135(t-1)+combi135(t-3)+combi135(t-5);
	}

	int ugly(int t){
		cerr<< "In ugly"<<endl;
		int arr[t];
		arr[0] = 1;
		int n2=0, n3=0, n5 = 0;
		int nmp2 = 2, nmp3 = 3, nmp5 = 5, nun = 1;
		for ( int i = 1; i < t; i++){
			nun = min(nmp2, min(nmp3, nmp5));
			arr[i] = nun;
			if (nun == nmp2)
			{
				n2++;
				nmp2 = arr[n2]*2;
			}
			if (nun == nmp3)
			{
				n3++;
				nmp3= arr[n3]*3;
			}
			if (nun == nmp5)
			{
				n5++;
				nmp5 = arr[n5]*5;
			}
		}
		cerr<< "Out ugly"<<endl;
		return arr[t-1];
	}
	int findGCD(int a, int b){
		Imp_prop p;
		return p.gcd(a,b);
	}
};

bool checkPali(string s1){
	int len=s1.length();

	if(len==1)
		return true;
	else if(s1.length()%2 == 0){
		if(s1.substr(0,len/2) == s1.substr(len/2, len/2) )
			return true;
		else
			return false;
	}
	else{
		if( s1.substr(0,len/2) == s1.substr(len/2+1, len/2) )
			return true;
		else
			return false;
	}
}

void findPalindroms(string s){
	set<string> mp;
	int len=1;
	while(len <= s.length()){
		for(int i=0; i<=s.length()-len; i++){
			string s1 = s.substr(i,len);
//			cerr<<"String s1 is: "<<s1<<endl;
			if(checkPali(s1))
				mp.insert(s1);
		}
		len++;
	}
	for(auto i:mp){
		cout<<i<<endl;
	}
}
/// sndnfdsalkg

class TreeNode
{
    public:
    int val, lval, rval, thd;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) { val = x; }
};

set<TreeNode*> s;
stack<TreeNode*> st;

// Function to build tree using given traversal
TreeNode* buildTree(int inorder[], int preorder[], int n)
{

    TreeNode* root = NULL;
    for (int pre = 0, in = 0; pre < n;)
    {

        TreeNode* node = NULL;
        do
        {
            node = new TreeNode(preorder[pre]);
            if (root == NULL)
            {
                root = node;
            }
            if (st.size() > 0)
            {
                if (s.find(st.top()) != s.end())
                {
                    s.erase(st.top());
                    st.top()->right = node;
                    st.pop();
                }
                else
                {
                    st.top()->left = node;
                }
            }
            st.push(node);
        } while (preorder[pre++] != inorder[in] && pre < n);

        node = NULL;
        while (st.size() > 0 && in < n &&
                st.top()->val == inorder[in])
        {
            node = st.top();
            st.pop();
            in++;
        }

        if (node != NULL)
        {
            s.insert(node);
            st.push(node);
        }
    }

    return root;
}
int n, c[100][100], nl=0, nr=0;
// Function to print tree in Inorder
void printInorder(TreeNode* node)
{
    if (node == NULL)
        return;
	 printInorder(node->left);
    // cout << "Node: " << node->val << " Left: " << node->lval << " Right: " << node->rval << " Thd: " << node->thd << endl;
    cout<<node->thd<<' ';
    printInorder(node->right);
}

void setVal(TreeNode *node){
	if(node==NULL) return;
	setVal(node->left);
	node->lval = c[node->val - 1][0];
	node->rval = c[node->val - 1][1];
	setVal(node->right);
}

void leftTree(TreeNode *dum);

void letsYoink(TreeNode* node){
	if(node==NULL) return;
	letsYoink(node->left);
	nl = node->lval;
	nr = node->rval;
	TreeNode *dum = node;
	leftTree(dum->left);
	node->thd = nl-nr;
	nl=0;
	nr=0;
	letsYoink(node->right);
}

void leftTree(TreeNode *dum){
	if(dum==NULL) return;
	leftTree(dum->left);
	nl+=dum->lval;
	nr+=dum->rval;
	leftTree(dum->right);
}

/// 83428042
int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
	#endif

	ios::sync_with_stdio(false);
	cin.tie(0);

    cout<<"Added login feature!"<<endl;
//	cin>>n;
//	int a[n],b[n];
//	for(int i=0; i<n; i++) cin>>a[i];
//	for(int i=0; i<n; i++) cin>>b[i];
//	for(int i=0; i<n; i++) cin>>c[i][0]>>c[i][1];
//
//	TreeNode* root = buildTree(a, b, n);
//	setVal(root);
//	letsYoink(root);
//	printInorder(root);



	return 0;
}

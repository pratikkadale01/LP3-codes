#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class node{
    public:
        int data=0;
        node* left=nullptr;
        node* right=nullptr;
};

class comp{
    public:
        bool operator()(const node* a,const node* b){
            return (a->data > b->data); 
        }      
};

class Solution
{
	public:
	    void helper(vector<string>& ans,string& local,node* root){
	        if(!root->left && !root->right){
	            ans.push_back(local);
	            return;
	        }
	        local.push_back('0');
	        helper(ans,local,root->left);
	        local.pop_back();
	        local.push_back('1');
	        helper(ans,local,root->right);
	        local.pop_back();
	    }
	
		vector<string> huffmanCodes(string S,vector<int> f,int N){
		    priority_queue<node*,vector<node*>,comp> p; 
		    for(auto i:f){
		        node* a = new node();
		        a->data = i;
		        p.push(a);
		    }
		    while(p.size()>1){
		        node* a = p.top();
		        p.pop();
		        node* b = p.top();
		        p.pop();
		        node* c = new node();
		        c->data = a->data+b->data;
		        c->left = a;
		        c->right =b;
		        p.push(c);
		    }
		    node* root = p.top();
            vector<string> ans;
            string local;
            helper(ans,local,root);
            return ans;
		}
};


int main(){
	    string S;
	    cin >> S;
	    int N = S.length();
	    vector<int> f(N);
	    for(int i=0;i<N;i++){
	        cin>>f[i];
	    }
	    Solution ob;
	    vector<string> ans = ob.huffmanCodes(S,f,N);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
	return 0;
}
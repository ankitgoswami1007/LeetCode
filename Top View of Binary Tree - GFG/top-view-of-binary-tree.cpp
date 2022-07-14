// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends


/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
       
    /*  pair < int , Node*> p , p1  ;
      map <int , int>  m ;
      vector <int> ans ;
      int line = 0 ;
      queue<pair < int , Node*> > q ;
      
      p1.first = line ;
      p1.second = root;
     // q.push(p1);
      q.push({line , root});
      
      while(! q.empty()){
          
         pair < int , Node*> temp ;
         temp = q.front();
         q.pop();
         Node* node = temp.second ;
         int ln  = temp.first ;
         
         
         if(m.find(ln) == m.end() ){
             m[ln] = node->data;
         }
         
         
         if(node->left != NULL){
             q.push(make_pair(ln-1,node->left ));
         }
          if(node->right != NULL){
             q.push(make_pair(ln+1,node->right ));
         }
         
      }
    
    
     for(auto it : m){
         ans.push_back (it.second);
      }
      return ans ;
     } */
     
    pair <Node*, int> pr;
	map<int, Node*> mp;
	queue<pair<Node*, int>> q;
	
	q.push({root, 0});
	
	while(!q.empty()){
		
		pair<Node*, int> temp = q.front();
		Node* cur = temp.first;
		int i = temp.second;
		q.pop();
		
		if(mp.find(temp.second) == mp.end()){
			mp[temp.second] = temp.first;
		}
		
		if(cur->left){
			q.push({cur->left, i-1});
		}
		if(cur->right){
			q.push({cur->right, i+1});
		}
	}
	
	vector<int> ans;
	for (auto i : mp) {
        ans.push_back(i.second->data);
	}	
	return ans;
    }
};



// { Driver Code Starts.

int main() {
    int tc;
    cin>>tc;
    cin.ignore(256, '\n');
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        vector<int> vec = ob.topView(root);
        for(int x : vec)
            cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
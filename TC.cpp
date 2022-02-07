class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int>v;
          if(root ==NULL)
        {
            return v;
        }
        
        queue<pair<Node*,int>>q;
        map<int,int> map;
        Node *temp=root;
        q.push({root,0});
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            Node *t=it.first;
            int line=it.second;
            if(map.find(line) == map.end())
            {
                map[line]=t->data; 
            }
           
            
            if(t->left!=NULL)
            {
                q.push({t->left,line-1});
            }
            if(t->right!=NULL)
            {
                q.push({t->right,line+1});
            }
        }
        
        for(auto itr:map)
        {
            v.push_back(itr.second);
        }
          
    }

};

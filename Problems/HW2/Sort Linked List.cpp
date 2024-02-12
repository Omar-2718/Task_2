/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/
bool cmp(pair<int,Node*>a,pair<int,Node*>b){
    return a.first < b.first;
}
Node* sortList(Node* head){
    // Write your code here.
    vector<pair<int,Node*>>arr;
    for(Node *i = head;i;i=i->next){
        arr.push_back({i->data,i});
    }
    
    sort(arr.begin(),arr.end(),cmp);
    arr.push_back({-1,nullptr});

    for(int i =0;i<arr.size() -1;i++){
        arr[i].second->next = arr[i+1].second;
    }
    head = arr[0].second;
    return head;
}

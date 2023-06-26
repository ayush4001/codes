 #include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    bool flag;
    Node(int data){
        this->flag=false;
        this->data=data;
        this->next=NULL;
    }
};


void insert(Node* &head,int d){
    Node* temp=new Node(d);
    temp->next=head;
    head=temp;
}

int length(Node* head){
    int c=0;
    while(head!=NULL){
        c+=1;
        head=head->next;
    }
    return c;
}


int loopcheck(Node* head){
    while(true){
        if(head==NULL){
            return 0;
            }
        else if(head->flag==true){
            return head->data;
            }
        else{
            head->flag=true;
            head=head->next;
            }
    }
}

void reverse(Node* &head){
    Node* prev=NULL;
    Node* current=head;
    while(head!=NULL){
        head=head->next;
        current->next=prev;
        prev=current;
        current=head; 
        
    }
    head=prev;
    
}

Node* sum(Node* head1,Node* head2){
    Node* ans=NULL;
    Node* temp=ans;
    reverse(head1);
    reverse(head2);
    int sum=0;
    int rem=0;
    while(head1!=NULL && head2!=NULL){
        sum=head1->data+head2->data+rem;
        insert(temp,sum%10);
        rem=(sum/10);
        head1=head1->next;
        head2=head2->next;
    }
    while(head1!=NULL){
        sum=head1->data+rem;
        insert(temp,sum%10);
        rem=(sum/10);
        head1=head1->next;
       
    }
    while(head2!=NULL){
        sum=head2->data+rem;
        insert(temp,sum%10);
        rem=(sum/10);
        head2=head2->next;
       
    }
    if(rem!=0){insert(temp,rem);}
    return temp;
}


















void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<' ';
        head=head->next;
    }
    cout<<endl;   
}








void duplicate(Node* head){
    Node* prev=NULL;
    while(head!=NULL){
        if(prev->data!=head->data){
            cout<<"yes"<<endl;
            prev=head;
            head=head->next;
        }
        else{
            head=head->next;
            prev->next=head;
            
        }


    }
}




 int main(){
    Node* node1=new Node(0);
    Node* node2=new Node(3);
    Node* head1=node1;
    Node* head2=node2;
    insert(head1,1);
    insert(head2,2);
    insert(head1,2);
    //insert(head2,9);
    
    print(head1);
    print(head2);
    Node* smu1=sum(head1,head2);
    print(smu1);
    
    
    

}








// This is an example which depicts the usage of Unrolled Linked List which can be used as an alternative for some databaes

// In this example we are considering two databases in the form of an array and an unrolled linked list. one database stores the names of departments and the other stores the 
// top 3 facuty of that department

struct Top_3_Faculty {
  string faculty[3];
  struct Top_3_Faculty* next;
};

struct Top_3_Faculty* head = NULL;

int main(){
  int i,j;
  string departments[] = {"AI", "CSE", "CE", "EE", "EP", "ES", "MA", "MS"}
  int length = sizeof(departmets)/sizeof(string);
  
  struct Top_3_Faculty* temp = NULL;
  for (i=0;i<length;i++){
    node = (struct Top_3_Faculty*)malloc(sizeof(struct Top_3_Faculty));
    
    if (!head){
      head = node;
      node->next = NULL;
    }
    temp = head;
    
    while (temp->next!=NULL)
      temp = temp->next;
    
    for (j=0;j<3;j++){
      temp-> Faculty[j] = department[i]+"_"+string(j);
    }
    
    temp->next = node;
    node->next = NULL;
  }
  
  return 0;
}

#include <iostream>
using namespace std;

int main() {
    
    int arr[2] = {4,2};

    cout << 0 [arr] << " \\\n" << 1 [arr] <<endl;
    
    
    cout << endl;
    return 0;
}


// min = n; i = 0;

// while (___________) {	

//      temp = A[i]; j = i;

//      while (________) {

//      A[j] = ________	

//      j= (j + k) mod n ;

//      If ( j< min ) then

//          min = j;

// }

// A[(n + i — k) mod n] = _________

// i = __________


// void fun(struct node **head_ref)
// {
//     struct node *temp = NULL;
//     struct node *current = *head_ref;

//     while (current !=  NULL)
//     {
//         temp = current->prev;
//         current->prev = current->next;
//         current->next = temp;
//         current = current->prev;
//     }

//     if(temp != NULL )
//         *head_ref = temp->prev;
// }
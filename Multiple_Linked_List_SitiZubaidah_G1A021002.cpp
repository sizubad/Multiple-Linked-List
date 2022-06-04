//Siti Zubaidah
//G1A021002
//Informatika B
// multilevel linked list
 
#include <bits/stdc++.h>
using namespace std;
 
// Pernyataan Node
class Node {
public:
    int data;
    Node* next;
    Node* child;
};
 
// Fungsi untuk Membuat sebuah linked list dengan n(ukuran) node mengembalikan kepala pointer

Node* createList(int* arr, int n)
{
    Node* head = NULL;
    Node* tmp;
 
    // Melintasi array yang dilewati
    for (int i = 0; i < n; i++) {
        // Membuat sebuah node jika daftar kosong
        if (head == NULL) {
            tmp = head = new Node();
        }
        else {
            tmp->next = new Node();
            tmp = tmp->next;
        }
        //  Membuat Node dengan data dan mengatur anak dan pointer selanjutnya null

        tmp->data = arr[i];
        tmp->next = tmp->child = NULL;
    }
    return head;
}
 
//  Print linked list
void printMultiLevelList(Node* head)
{
    // While head bujan null
    while (head) {
        if (head->child) {
            printMultiLevelList(head->child);
        }
        cout << head->data << " ";
        head = head->next;
    }
}
 
// Driver code
int main()
{
    //  Insialisasi data dalam array
    int arr1[3] = { 1, 2, 3 };
    int arr2[2] = { 5, 6 };
    int arr3[1] = { 4 };
    int arr4[3] = { 7, 8, 9 };
 
    // Membuat empat linked list melewati array dan ukuran array sebagai paremeter
    Node* head1 = createList(arr1, 3);
    Node* head2 = createList(arr2, 2);
    Node* head3 = createList(arr3, 1);
    Node* head4 = createList(arr4, 3);
 
    //  Inisialisasi anak dan pointer selanjutnya
    head1->child = head2;
    head1->next->next->child = head3;
    head2->next->child = head4;
 
    // Membuat sebuah Pointer null
    Node* head = NULL;
    head = head1;
 
    // fungsi untuk memanggil prin
    printMultiLevelList(head);
 
    return 0;
}

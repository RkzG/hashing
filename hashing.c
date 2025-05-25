#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Code By : Franky Wahyu Prasetyo / 2702507920
#define TABLE_SIZE 10 //Total tabel/index nya ada 10
#define MAX_NAME 100 //Total variabel nama nya ada 100 character

// Struktur Node untuk data hewan
typedef struct Animal {
    char nama_ilmiah[MAX_NAME];
    char nama_umum[MAX_NAME];
    char klasifikasi[MAX_NAME];
    struct Animal* next;
} Animal;

// Hashing table menggunakan chaining
Animal* hashTable[TABLE_SIZE];

// Function hashing sederhana
int hash(char* key) {
    int sum = 0;
    for(int i = 0; key[i] != '\0'; i++) {
        sum += key[i];
    }
    return sum % TABLE_SIZE;
}

//Code By : Franky Wahyu Prasetyo / 2702507920
// Insert data ke hash table
void insert(char* nama_ilmiah, char* nama_umum, char* klasifikasi) {
    int index = hash(nama_ilmiah);

    Animal* newNode = (Animal*)malloc(sizeof(Animal));
    strcpy(newNode->nama_ilmiah, nama_ilmiah);
    strcpy(newNode->nama_umum, nama_umum);
    strcpy(newNode->klasifikasi, klasifikasi);
    newNode->next = NULL;

    // Proses chaining jika terjadi collision
    if(hashTable[index] == NULL) {
        hashTable[index] = newNode;
    } else {
        Animal* temp = hashTable[index];
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

//Code By : Franky Wahyu Prasetyo / 2702507920
// Get tabel hash
void display() {
    for(int i = 0; i < TABLE_SIZE; i++) {
        printf("Index %d:\n", i);
        Animal* temp = hashTable[i];
        if(temp == NULL) {
            printf("  Kosong\n");
        } else {
            while(temp != NULL) {
                printf("  [%s | %s | %s] ->\n", temp->nama_ilmiah, temp->nama_umum, temp->klasifikasi);
                temp = temp->next;
            }
            printf("  NULL\n");
        }
    }
}

//Code By : Franky Wahyu Prasetyo / 2702507920
int main() {
    // Inisialisasi hash table kosong
    for(int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }

    // Insert data
    insert("Phascolarctos Cinereus", "Koala", "Mamalia");
    insert("Oryctolagus Cuniculus", "Kelinci", "Mamalia");
    insert("Hippopotamus Amphibius", "Kuda Nil", "Mamalia");
    insert("Gorilla Gorilla", "Gorila", "Mamalia");
    insert("Ailuropoda Melanoleuca", "Panda", "Mamalia");
    insert("Apis Mellifera", "Lebah Madu", "Serangga");
    insert("Bos Javanicus", "Banteng", "Mamalia");

    display();

    return 0;
}

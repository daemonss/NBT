#include "menu.h"
#include <stdio.h>
#include <stdlib.h>

// Fungsi untuk membersihkan layar (cross-platform)
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Menampilkan menu utama
void displayMainMenu() {
    clearScreen();
    printf("=== PROGRAM NON-BINARY TREE ===\n");
    printf("1. Traversal PreOrder\n");
    printf("2. Traversal InOrder\n");
    printf("3. Traversal PostOrder\n");
    printf("4. Traversal Level Order\n");
    printf("5. Print Tree\n");
    printf("6. Search node Tree\n");
    printf("7. Jumlah Daun/leaf\n");
    printf("8. Mencari Level node Tree\n");
    printf("9. Kedalaman Tree\n");
    printf("10. Membandingkan 2 node Tree\n");
    printf("11. Exit \n");
    printf("Pilih Menu: ");
}

// Menangani input menu
void handleMenu(Isi_Tree tree) {
    int choice;
    char input, node1, node2;
    
    do {
        displayMainMenu();
        scanf("%d", &choice);
        clearScreen();
        
        switch(choice) {
            case 1:
                printf("Hasil PreOrder: ");
                PreOrder(tree);
                break;
            case 2:
                printf("Hasil InOrder: ");
                InOrder(tree);
                break;
            case 3:
                printf("Hasil PostOrder: ");
                PostOrder(tree);
                break;
            case 4:
                printf("Hasil LevelOrder: ");
                Level_order(tree, nbElmt(tree));
                break;
            case 5:
                printTreeDetails(tree);
                break;
            case 6:
                printf("Masukkan node yang dicari: ");
                scanf(" %c", &input);
                printf("Node %c %s\n", input, Search(tree, input) ? "ditemukan" : "tidak ditemukan");
                break;
            case 7:
                printf("Jumlah daun: %d\n", nbDaun(tree));
                break;
            case 8:
                printf("Masukkan node: ");
                scanf(" %c", &input);
                printf("Level node %c: %d\n", input, Level(tree, input));
                break;
            case 9:
                printf("Kedalaman tree: %d\n", Depth(tree));
                break;
            case 10:
                printf("Masukkan node 1 dan 2 (contoh: A B): ");
                scanf(" %c %c", &node1, &node2);
                printf("Node terbesar: %c\n", Max(node1, node2));
                break;
            case 11:
                printf("Terima kasih!\n");
                exit(0);
            default:
                printf("Input tidak valid!\n");
        }
        printf("\nTekan enter untuk melanjutkan...");
        getchar(); getchar();
    } while(choice != 11);
}

// Menampilkan struktur tree secara detail
void printTreeDetails(Isi_Tree P) {
    printf("=== Struktur Tree ===\n");
    PrintTree(P);
    PrintTreeVisual(P);
}
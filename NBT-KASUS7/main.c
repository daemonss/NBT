#include "Spesifikasi.h"
#include <stdio.h>

int main() {
    Isi_Tree myTree;
    int jumlahNode = 10;  // Sesuaikan dengan total node (A-J)

    Create_tree(myTree, jumlahNode);

    printf("=== Hasil Traversal ===\n");
    printf("PreOrder  : ");
    PreOrder(myTree);

    printf("InOrder: ");
    InOrder(myTree);

    printf("PostOrder : ");
    PostOrder(myTree);

    printf("LevelOrder: ");
    Level_order(myTree, jumlahNode);

    printf("\n=== Informasi Pohon ===\n");
    printf("Total node: %d\n", nbElmt(myTree));
    printf("Total daun: %d\n", nbDaun(myTree));
    printf("Kedalaman : %d\n", Depth(myTree));
    printf("Level 'H' : %d\n", Level(myTree, 'H'));

    printf("\nCari 'X' : %s\n", Search(myTree, 'X') ? "Ditemukan" : "Tidak Ditemukan");
    printf("Max(A,G) : %c\n", Max('A', 'G'));

    printf("\n=== Struktur Tabel ===\n");
    PrintTree(myTree);

    // Tampilkan visualisasi pohon
    PrintTreeVisual(myTree);

    return 0;
}
#include "Spesifikasi.h"
#include <stdio.h>

// Helper function untuk traversal PreOrder
void preOrderHelper(Isi_Tree P, address node) {
    if (node == nil) return;
    printf("%c ", P[node].info);
    address child = P[node].ps_fs;
    while (child != nil) {
        preOrderHelper(P, child);
        child = P[child].ps_nb;
    }
}

void PreOrder(Isi_Tree P) {
    if (IsEmpty(P)) return;
    preOrderHelper(P, 1);
    printf("\n");
}

// Helper function untuk traversal InOrder
void inOrderHelper(Isi_Tree P, address node) {
    if (node == nil) return;
    address child = P[node].ps_fs;
    if (child != nil) {
        inOrderHelper(P, child);
    }
    printf("%c ", P[node].info);
    if (child != nil) {
        address nextBrother = P[child].ps_nb;
        while (nextBrother != nil) {
            inOrderHelper(P, nextBrother);
            nextBrother = P[nextBrother].ps_nb;
        }
    }
}

void InOrder(Isi_Tree P) {
    if (IsEmpty(P)) return;
    inOrderHelper(P, 1);
    printf("\n");
}

// Helper function untuk traversal PostOrder
void postOrderHelper(Isi_Tree P, address node) {
    if (node == nil) return;
    address child = P[node].ps_fs;
    while (child != nil) {
        postOrderHelper(P, child);
        child = P[child].ps_nb;
    }
    printf("%c ", P[node].info);
}

void PostOrder(Isi_Tree P) {
    if (IsEmpty(P)) return;
    postOrderHelper(P, 1);
    printf("\n");
}

void Level_order(Isi_Tree X, int Maks_node) {
    if (IsEmpty(X)) return;
    address queue[jml_maks + 1];
    int front = 0, rear = 0;
    queue[rear++] = 1; // Root

    while (front < rear) {
        address current = queue[front++];
        printf("%c ", X[current].info);

        // Enqueue semua anak
        address child = X[current].ps_fs;
        while (child != nil) {
            queue[rear++] = child;
            child = X[child].ps_nb;
        }
    }
    printf("\n");
}

void PrintTree(Isi_Tree P) {
    printf("Index | Info | First Child | Next Brother | Parent\n");
    for (int i = 1; i <= jml_maks; i++) {
        if (P[i].info == '\0') continue;
        printf("%5d | %4c | %11d | %12d | %6d\n", i, P[i].info, P[i].ps_fs, P[i].ps_nb, P[i].ps_pr);
    }
}

boolean IsEmpty(Isi_Tree P) {
    return (P[1].info == '\0');
}

boolean Search(Isi_Tree P, infotype X) {
    for (int i = 1; i <= jml_maks; i++) {
        if (P[i].info == X) return true;
    }
    return false;
}

int nbElmt(Isi_Tree P) {
    int count = 0;
    for (int i = 1; i <= jml_maks; i++) {
        if (P[i].info != '\0') count++;
    }
    return count;
}

int nbDaun(Isi_Tree P) {
    int count = 0;
    for (int i = 1; i <= jml_maks; i++) {
        if (P[i].info != '\0' && P[i].ps_fs == nil) count++;
    }
    return count;
}

int Level(Isi_Tree P, infotype X) {
    for (int i = 1; i <= jml_maks; i++) {
        if (P[i].info == X) {
            int level = 0;
            address parent = P[i].ps_pr;
            while (parent != nil) {
                level++;
                parent = P[parent].ps_pr;
            }
            return level;
        }
    }
    return -1;
}

int Depth(Isi_Tree P) {
    int maxDepth = -1;
    for (int i = 1; i <= jml_maks; i++) {
        if (P[i].info != '\0') {
            int currentLevel = Level(P, P[i].info);
            if (currentLevel > maxDepth) maxDepth = currentLevel;
        }
    }
    return maxDepth;
}

int Max(infotype Data1, infotype Data2) {
    return (Data1 > Data2) ? Data1 : Data2;
}

void Create_tree(Isi_Tree X, int Jml_Node) {
    // Inisialisasi semua node ke nilai default
    for (int i = 1; i <= jml_maks; i++) {
        X[i].info = '\0';
        X[i].ps_fs = nil;
        X[i].ps_nb = nil;
        X[i].ps_pr = nil;
    }

    // Root 'A' di index 1
    X[1].info = 'A';
    X[1].ps_fs = 2;
    X[1].ps_pr = nil;

    // Node 'B' di index 2 (Anak A)
    X[2].info = 'B';
    X[2].ps_fs = 4;   // Anak pertama: D
    X[2].ps_nb = 3;   // Saudara: C
    X[2].ps_pr = 1;

    // Node 'C' di index 3 (Saudara B)
    X[3].info = 'C';
    X[3].ps_fs = 6;   // Anak pertama: F
    X[3].ps_nb = nil;
    X[3].ps_pr = 1;

    // Node 'D' di index 4 (Anak B)
    X[4].info = 'D';
    X[4].ps_nb = 5;   // Saudara: E
    X[4].ps_pr = 2;

    // Node 'E' di index 5 (Saudara D) - PUNYA ANAK I & J
    X[5].info = 'E';
    X[5].ps_fs = 9;   // Anak pertama: I
    X[5].ps_nb = nil;
    X[5].ps_pr = 2;

    // Node 'F' di index 6 (Anak C)
    X[6].info = 'F';
    X[6].ps_nb = 7;   // Saudara: G
    X[6].ps_pr = 3;

    // Node 'G' di index 7 (Saudara F)
    X[7].info = 'G';
    X[7].ps_nb = 8;   // Saudara: H
    X[7].ps_pr = 3;

    // Node 'H' di index 8 (Saudara G)
    X[8].info = 'H';
    X[8].ps_pr = 3;

    // Node 'I' di index 9 (Anak E)
    X[9].info = 'I';
    X[9].ps_nb = 10;  // Saudara: J
    X[9].ps_pr = 5;

    // Node 'J' di index 10 (Saudara I)
    X[10].info = 'J';
    X[10].ps_nb = nil;
    X[10].ps_pr = 5;

    // Set sisa node ke nilai default (mulai dari 11)
    for (int i = 11; i <= jml_maks; i++) {
        X[i].info = '\0';
        X[i].ps_fs = nil;
        X[i].ps_nb = nil;
        X[i].ps_pr = nil;
    }
}

static void PrintTreeVisualHelper(Isi_Tree P, address node, int depth, boolean isLast, boolean ancestorsLast[]) {
    if (node == nil) return;

    // Print indentasi
    for (int i = 0; i < depth; i++) {
        if (ancestorsLast[i]) {
            printf("    "); // Spasi jika parent adalah anak terakhir
        } else {
            printf("│   "); // Garis vertikal jika parent bukan anak terakhir
        }
    }

    // Print simbol cabang
    printf(isLast ? "└── " : "├── ");
    printf("%c\n", P[node].info);

    // Update status "last" untuk level saat ini
    boolean newAncestorsLast[jml_maks];
    for (int i = 0; i < depth; i++) {
        newAncestorsLast[i] = ancestorsLast[i];
    }
    newAncestorsLast[depth] = isLast; // Simpan status node saat ini

    // Traversal ke anak
    address child = P[node].ps_fs;
    while (child != nil) {
        boolean lastChild = (P[child].ps_nb == nil);
        PrintTreeVisualHelper(P, child, depth + 1, lastChild, newAncestorsLast);
        child = P[child].ps_nb;
    }
}

void PrintTreeVisual(Isi_Tree P) {
    if (!IsEmpty(P)) {
        printf("\n=== Visualisasi Pohon ===\n");
        printf("    %c\n", P[1].info);
        boolean ancestorsLast[jml_maks] = {false};
        address child = P[1].ps_fs;
        while (child != nil) {
            boolean lastChild = (P[child].ps_nb == nil);
            ancestorsLast[0] = true;
            PrintTreeVisualHelper(P, child, 1, lastChild, ancestorsLast);
            child = P[child].ps_nb;
        }
    }
}

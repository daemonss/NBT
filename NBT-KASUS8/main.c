#include "menu.h"

int main() {
    Isi_Tree myTree;
    Create_tree(myTree, 10); // Inisialisasi tree dengan 10 node
    
    handleMenu(myTree); // Memulai menu interaktif
    return 0;
}
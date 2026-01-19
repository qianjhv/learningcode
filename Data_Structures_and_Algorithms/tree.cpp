clas  PTNode {
  int parent;
  int data;
}

class PTree {
  PTNode nodes[];
}

class CTNode {
  CTNode* next;
  int children;
}

class CTBox {
  int data;
  CTNode* first_child;
}

class CTree {
  CTBox nodes[];
}











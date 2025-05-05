

bool mirror(Node* n1, Node* n2) {
    if (n1 == nullptr && n2 == nullptr) {
        return true;
    }
    if (n1 == nullptr) {
        return false;
    } 
    if (n2 == nullptr) {
        return false;
    }

    if (n1->value != n2->value) {
        return false;
    }

    return (mirror(n1->left, n2->left) && mirror(n2->right, n1->right)) || 
            (mirror(n1->left, n2->right) && mirror(n1->right, n2->left));
}
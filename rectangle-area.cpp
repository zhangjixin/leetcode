class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int leftA = max(A, E), leftB = max(B, F);
        int rightA = min(C, G), rightB = min(D, H);
        if (leftA >= rightA || leftB >= rightB) 
            return (G - E) * (H - F) + (C - A) * (D - B);
        return (G - E) * (H - F) - (rightA - leftA) * (rightB - leftB) + (C - A) * (D - B);
    }
};
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // transpose kiya hua hai pahle
        for(int i = 0; i < n ; i++){  //ye start hoga 00 se islie i =0   
            for(int j = i + 1; j < n; j ++){ //aur ye bi niche se start hoga to dig ke 
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        // uske bad reverse kardia hai then 90 degre clockwise ho jayega 
        for(int i = 0; i < n; i++){
            int start = 0, end = n - 1;
            while(start < end){
                swap(matrix[i][start],matrix[i][end]);
                start++, end--;
            }
        }
        
    }
};
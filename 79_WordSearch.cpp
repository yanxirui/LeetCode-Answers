class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(word.length() == 0) return true;
        if(board.empty() || board[0].empty() || word.length() > board.size()*board[0].size()) return false;
        vector<vector<bool>> used;
        vector<bool> tmp;
        for(int i=0; i<board[0].size(); i++){
            tmp.push_back(false); 
        }
        for(int i=0; i<board.size(); i++){
            used.push_back(tmp);
        }
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(search(board, word, 0, i, j, used)) return true;   
            }
        }
        return false;
    }
    
    bool search(vector<vector<char>>& board, string word, int index, int i, int j, vector<vector<bool>>& used){
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || used[i][j] || word[index] != board[i][j]) return false;
        if(index == word.length()-1) return true;
        used[i][j] = true;
        bool res = search(board,word,index+1,i+1,j,used) 
                || search(board,word,index+1,i,j+1,used)
                || search(board,word,index+1,i-1,j,used)
                || search(board,word,index+1,i,j-1,used);
        used[i][j] = false;
        return res;
    }
    
};
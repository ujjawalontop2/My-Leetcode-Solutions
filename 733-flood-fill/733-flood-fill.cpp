class Solution {
public:
    
    void fill(vector<vector<int>>& image, int sr, int sc, int ncolor,int ocolor){
        if(sr<0 || sc<0 || sr>=image.size() || sc>= image[0].size() || image[sr][sc]!=ocolor){
            return ;
        }
        
        image[sr][sc]=ncolor;
        
        fill(image,sr+1,sc,ncolor,ocolor);
        fill(image,sr,sc+1,ncolor,ocolor);
        fill(image,sr-1,sc,ncolor,ocolor);
        fill(image,sr,sc-1,ncolor,ocolor);
        
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        if(image[sr][sc]==color || image.size()<=0) return image;
        
        fill(image,sr,sc,color,image[sr][sc]);
        
        return image;
        
    }
};
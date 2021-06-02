#include <vector>
#include <queue>
#include <string>
#include <tuple>

using namespace std;

// Leetcode https://leetcode.com/problems/cat-and-mouse-ii/

// Very impressive solution!

class Solution {
public:
    size_t xy_to_index(size_t x, size_t y)
    {
        return x + y * w;
    }
    
    pair<size_t, size_t> index_to_xy(size_t index)
    {
        return {index % w, index / w};
    }
    
    template<typename Func>
    void for_each_jump(const vector<string>& grid, size_t index, size_t jump, Func&& func)
    {
        const auto [x, y] = index_to_xy(index);
        func(xy_to_index(x, y));
        for(size_t step = 1; step <= jump && x + step < w && grid[x + step][y] != '#'; ++step)
            func(xy_to_index(x + step, y));
        for(size_t step = 1; step <= jump && x >= step && grid[x - step][y] != '#'; ++step)
            func(xy_to_index(x - step, y));
        for(size_t step = 1; step <= jump && y + step < h && grid[x][y + step] != '#'; ++step)
            func(xy_to_index(x, y + step));
        for(size_t step = 1; step <= jump && y >= step && grid[x][y - step] != '#'; ++step)
            func(xy_to_index(x, y - step));
    }
    
    bool canMouseWin(const vector<string>& grid, size_t cat_jump, size_t mouse_jump) {
        w = grid.size();
        h = grid.front().size();
        auto n = w * h;
        
        size_t cat_start;
        size_t mouse_start;
        size_t food;
        vector<vector<char>> cat_degree(n);
        vector<vector<char>> mouse_degree(n);
        for(size_t i = 0; i < w; ++i)
        {
            for(size_t j = 0; j < h; ++j)
            {
                const auto index = xy_to_index(i, j);
                if(grid[i][j] == '#')
                    continue;
                if(grid[i][j] == 'C')
                    cat_start = index;
                else if(grid[i][j] == 'M')
                    mouse_start = index;
                else if(grid[i][j] == 'F')
                    food = index;
                int degree = 0;
                for_each_jump(grid, index, cat_jump, [&](size_t){++degree;});
                cat_degree[index].resize(n, degree);
                degree = 0;
                for_each_jump(grid, index, mouse_jump, [&](size_t){++degree;});
                mouse_degree[index].resize(n, degree);
            }
        }
        
        queue<tuple<size_t, size_t, bool, bool>> frontier;
        for(size_t i = 0; i < w; ++i)
        {
            for(size_t j = 0; j < h; ++j)
            {                
                if(grid[i][j] == '#')
                    continue;
             
                const auto index = xy_to_index(i, j);
                frontier.emplace(index, index, true, true);
                frontier.emplace(food, index, true, true);
                frontier.emplace(index, food, false, false);
                mouse_degree[index][index] = 0;
                cat_degree[index][index] = 0;
                mouse_degree[food][index] = 0;
                cat_degree[food][index] = 0;
            }
        }
        
        while(!frontier.empty())
        {
            // const auto [cat, mouse, is_cat_moved, cat_win] = frontier.front();
            size_t cat, mouse;
            bool is_cat_moved, cat_win;
            tie(cat, mouse, is_cat_moved, cat_win) = frontier.front();
            //cout << cat << ' ' << mouse << ' ' << is_cat_moved << endl;
            frontier.pop();
            if(is_cat_moved) // mouse's turn
            {
                bool win = false;
                for_each_jump(grid, mouse, mouse_jump, [&,cat=cat,cat_win=cat_win](size_t index){
                    if(!mouse_degree[index][cat])
                        return;
                    if(cat_win)
                    {                        
                        if(!--mouse_degree[index][cat])
                        {
                            frontier.emplace(cat, index, false, true);
                            if(cat == cat_start && index == mouse_start)
                                win = true;
                        }
                    }
                    else
                    {          
                        if(cat == cat_start && index == mouse_start)
                            win = true;
                        mouse_degree[index][cat] = 0;
                        frontier.emplace(cat, index, false, false);
                    }
                });
                if(win)
                    return !cat_win;
            }
            else // cat's turn
            {
                for_each_jump(grid, cat, cat_jump, [&,mouse=mouse,cat_win=cat_win](size_t index){
                    if(!cat_degree[index][mouse])
                        return;
                    if(cat_win)
                    {
                        cat_degree[index][mouse] = 0;
                        frontier.emplace(index, mouse, true, true);
                    }
                    else
                    {
                        if(!--cat_degree[index][mouse])
                            frontier.emplace(index, mouse, true, false);
                    }
                });
            }            
        }
        
        return false;
    }
    
    size_t w;
    size_t h;
};
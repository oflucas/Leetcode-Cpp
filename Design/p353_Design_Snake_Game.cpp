typedef pair<int, int> Loc;
Loc operator +(const Loc& a, const Loc& b) {
        return {a.first + b.first, a.second + b.second};
}

class SnakeGame {
    unordered_map<string, Loc> dirs;
    int W, H, t;
    vector<Loc> foods;
    set<Loc> isBody;
    deque<Loc> snake;
    
public:
    /** Initialize your data structure here.
 *         @param width - screen width
 *                 @param height - screen height 
 *                         @param food - A list of food positions
 *                                 E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<pair<int, int>> food): W(width), H(height), t(0) {
        dirs.emplace("U", make_pair(-1, 0));
        dirs.emplace("D", make_pair(1, 0));
        dirs.emplace("L", make_pair(0, -1));
        dirs.emplace("R", make_pair(0, 1));
        foods = food;
        
        isBody.insert(make_pair(0, 0));
        snake.emplace_back(make_pair(0, 0));
    }
    
    /** Moves the snake.
 *         @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
 *                 @return The game's score after the move. Return -1 if game over. 
 *                         Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        Loc nextMove = snake.front() + dirs[direction];
        
        if (t < foods.size() && nextMove == foods[t])
            t++;
        else {
            isBody.erase(snake.back());
            snake.pop_back();
        }
        
        if (isDeadMove(nextMove))
            return -1;
            
        snake.push_front(nextMove);
        isBody.insert(nextMove);
        return t;
    }
    
    bool isDeadMove(const Loc& pos) {
        return pos.first < 0 || pos.first >= H || pos.second < 0 || pos.second >= W || isBody.count(pos);
    }
};

/**
 *  * Your SnakeGame object will be instantiated and called as such:
 *   * SnakeGame obj = new SnakeGame(width, height, food);
 *    * int param_1 = obj.move(direction);
 *     */

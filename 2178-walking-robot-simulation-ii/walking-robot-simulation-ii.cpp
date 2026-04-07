// class Robot {
// public:

//     // only positve cartesian plane hai 
//     // Right/EAst -> Up/North -> Left/West -> Bottom/South

//     // x ( 0 , a ) & y ( 0 , b )
//     // check the bound adn retry steps 
    
//     bool moved = false;
//     int idx = 0 ; 
//     vector<pair<int,int>> pos;
//     vector<int> dir;
//     unordered_map<int, string> toTheDirection = {
//         {0,"East"}, {1,"North"}, {2,"West"}, {3,"South"}
//     };


//     Robot(int width, int height) {
//         for (int i = 0; i < width; ++i) {
//             pos.emplace_back(i, 0);
//             dir.emplace_back(0);
//         }
//         for (int i = 1; i < height; ++i) {
//             pos.emplace_back(width - 1, i);
//             dir.emplace_back(1);
//         }
//         for (int i = width - 2; i >= 0; --i) {
//             pos.emplace_back(i, height - 1);
//             dir.emplace_back(2);
//         }
//         for (int i = height - 2; i > 0; --i) {
//             pos.emplace_back(0, i);
//             dir.emplace_back(3);
//         }
//         dir[0] = 3;
//     }
    
//     void step(int num) {
//         moved = true;
//         idx = (idx + num) % pos.size();
//     }
    
//     vector<int> getPos() {
//         return {pos[idx].first, pos[idx].second};
//     }
    
//     string getDir() {
//         if (!moved) {
//             return "East";
//         }
//         return toTheDirection[dir[idx]];
//     }
// };

// /**
//  * Your Robot object will be instantiated and called as such:
//  * Robot* obj = new Robot(width, height);
//  * obj->step(num);
//  * vector<int> param_2 = obj->getPos();
//  * string param_3 = obj->getDir();
//  */





// O(1)
class Robot {
public:
    int W, H, P;
    int pos = 0;
    bool hasMoved = false;

    Robot(int width, int height) {
        W = width - 1;
        H = height - 1;
        P = 2 * (W + H);
    }
    
    void step(int num) {
        hasMoved = true;
        pos = (pos + num) % P;
    }
    
    vector<int> getPos() {
        if(pos <= W) return {pos, 0};
        if(pos <= W + H) return {W, pos - W};
        if(pos <= 2 * W + H) return {W - (pos - (W + H)), H};
        return {0, H - (pos - (2 * W + H))};
    }
    
    string getDir() {
        if(! hasMoved) return "East";
        if(pos == 0) return "South";
        if(pos <= W) return "East";
        if(pos <= W + H) return "North";
        if(pos <= 2 * W + H) return "West";
        return "South";
    }
};
class BrowserHistory {
public:
    deque<string> history;
    int index;
    BrowserHistory(string homepage) {
        index=0;
        history.clear();
        history.push_back(homepage);
    }
    
    void visit(string url) {
        while (history.size() > index + 1) {
            history.pop_back();
        }

        history.push_back(url);
        index = history.size() - 1;
    }
    
    string back(int steps) {
        if(steps>index)
        {
            index=0;
        }else{
            index-=steps;
        }
        return history[index];
    }
    
    string forward(int steps) {
        if(steps>(history.size()-index-1))
        {
            index=history.size()-1;
        }else{
            index+=steps;
        }
        return history[index];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
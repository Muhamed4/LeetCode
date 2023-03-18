

// Link of Problem

// https://leetcode.com/problems/design-browser-history/

// 1472. Design Browser History






class BrowserHistory {
public:
    vector<string>websites;
    int cur_page;
    BrowserHistory(string homepage) {
        cur_page = 0;
        websites.push_back(homepage);
    }
    
    void visit(string url) {
        while((int)websites.size() - 1 > cur_page)websites.pop_back();
        if(websites.back() != url)websites.push_back(url);
        cur_page = (int)websites.size() - 1;
    }
    
    string back(int steps) {
        while(steps-- && cur_page > 0)cur_page--;
        return websites[cur_page];
    }
    
    string forward(int steps) {
        while(steps-- && cur_page < (int)websites.size() - 1)cur_page++;
        return websites[cur_page];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
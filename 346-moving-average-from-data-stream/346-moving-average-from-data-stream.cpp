class MovingAverage { 
private:
    int m_size;
    int m_sum;
    std::queue<int> numsQ;
                     
public:
    MovingAverage(int size): m_size(size), m_sum(0) {}
    
    double next(int val) {

        if(numsQ.size() == m_size)
        {     
            m_sum -= numsQ.front();
            numsQ.pop();              
        }
        
        m_sum += val;
        numsQ.push(val);
    
        return ( m_sum / (double)numsQ.size() );        
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
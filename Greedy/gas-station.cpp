int Solution::canCompleteCircuit(const vector<int> &gas, 
                            const vector<int> &cost)
{
    int N = gas.size();
    int sum = 0;
    int start = 0;
    int tank = 0;
    for(int i=0;i<N;i++)
    {
        sum += gas[i]-cost[i];
        tank += gas[i]-cost[i];
        if(tank<0)
        {
            start = i+1;
            tank = 0;
        }
    }

    if(sum<0) return -1;
    else return start;
}

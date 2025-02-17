#include <iostream>
#include <vector>
#include <queue>

class Process {
    public :
        int id;
        int work;
        int remaining_work;
        Process( int id, int workunits){
            this->id=id;
            this->work=workunits;
            this->remaining_work=this->work;
        }
};

class Scheduler {
    private:
    std::vector<Process> proceesses;
    int quantum;

    public:
     Scheduler( int  q){
        this->quantum=q;

     }

     void addProcess( int id,  int work){
        Process * pProcess=new  Process(id, work);
        this->proceesses.emplace_back(pProcess );
     }

    void schedule(){
        //logic for shedule
        std::queue<Process *> pProcessQueue;
        for(auto &process: this->proceesses){
            pProcessQueue.push(&process);
        }

        while(!pProcessQueue.empty()){

            Process * pCurrent= pProcessQueue.front();
            //
            pProcessQueue.pop();
            

        }


    }




};



int main(){

    return 0;


}
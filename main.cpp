#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

class Server
{
public:
    void addMessage(int ip, double time, string text)
    {
        if(time < last_time)
        {
            ++day_counter;
            if (day_counter >= 5)
                seekForSpammers();

        }
        auto new_ip = [](){for(auto it : ips) {if(it.ip == ip) return false;} return true;}
        if(new_ip())
            ips.push_back(ip);
        Mail m{time, text};
        ips.at(ips.find(ip)).addMail(m);
        last_time = time;
    }
    void seekForSpammers()
    {
        /*for(size_t i; i < ips.size(); ++i)
        {
            int sum_of_messages = 0;
            for(size_t j = ips[i].mails.size(); j < )
        }*/
    }
private:
    vector<Ip> ips;
    int day_counter;
    double last_time;
};

class Ip
{
public:
  Ip(int ip_) : ip(ip_) {}
    void addMail(Mail m)
    {
        int last_day = mails.rbegin()->first;
        if(last_day == 0 || mails[last_day].back().time > m.time)
        {
            vector<Mail> new_mails{m};
            mails[last_day+1] = new_mails;
        }
        else
            mails[last_day].push_back(m);
    }
    void markAsSpam()
    {
        is_spam = true;
    }
private:
    bool is_spam = false;
    int ip;
    map<int, vector<Mail>> mails;
};
struct Mail
{
    double time;
    string message;
};

int main()
{

    cout << "Hello world!" << endl;
    return 0;
}

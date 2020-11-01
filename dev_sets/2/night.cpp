#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

int main()
{
    int n; cin >> n;
    while (n--)
    {
        int w; cin >> w;
        int t1=0, t2=0;
        int lastT1Sleep=0, lastT2Sleep=0;
        int longestT1Continuity=0, longestT2Continuity=0;
        for (int i = 0; i < w; i++)
        {
            string w, s;
            cin >> w >> s;
            int time = 0;

            int sleepTime = 0, wakeTime = 0;
            if (s[1] == ':')
            {
                sleepTime = (s[0]-'0'+1)*60 + (s[2]-'0')*10 + (s[3]-'0');
                time += sleepTime;
                //cout << "adding " << sleepTime << " minutes\n";
            }
            else
            {
                sleepTime = (s[1]-'0'-1)*60 + (s[3]-'0') * 10 + (s[4]-'0');
                time += sleepTime;
                //cout << "adding " << sleepTime << " minutes\n";
            }

            if (w[1] == ':')
            {
                wakeTime = (w[0]-'0'+1)*60 + (w[2]-'0')*10 + (w[3]-'0');
                time -= wakeTime;
                //cout << "removing " << wakeTime << " minutes\n";
            }
            else
            {
                wakeTime = (w[1]-'0'-1)*60 + (w[3]-'0')*10 + (w[4]-'0');
                time -= wakeTime;
                //cout << "removing " << wakeTime << " minutes\n";
            }

            //cout << "shift " << i+1 << " is " << time << " minutes\n";
            if (i%2 == 0)
                t1+=time;
            else
                t2+=time;

            if (i % 2 == 0)
            {
                if (wakeTime - lastT1Sleep > longestT1Continuity)
                    longestT1Continuity = wakeTime - lastT1Sleep;
            }
            else
                if (wakeTime - lastT2Sleep > longestT2Continuity)
                    longestT2Continuity = wakeTime - lastT2Sleep;

            //cout << "t1cont = " << longestT1Continuity << " t2cont = " << longestT2Continuity << "\n";

            if (i % 2 == 0)
                lastT1Sleep = sleepTime;
            else
                lastT2Sleep = sleepTime;
        }


        if (t1 < t2)
            cout << "FIRST";
        else if (t2 < t1)
            cout << "SECOND";
        else
        {
            // calc continuity of sleep
            int wakeTime = 540;
            if (wakeTime - lastT1Sleep > longestT1Continuity)
                longestT1Continuity = wakeTime - lastT1Sleep;
            if (wakeTime - lastT2Sleep > longestT2Continuity)
                longestT2Continuity = wakeTime - lastT2Sleep;

            //cout << "CONFLICT EVAL WITH T1CONT = " << longestT1Continuity << " AND T2CONT = " << longestT2Continuity << "\n";
            
            if (longestT1Continuity > longestT2Continuity)
                cout << "FIRST";
            else
                cout << "SECOND";
        }
        cout << "\n";
    }
    return 0;
}

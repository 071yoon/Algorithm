#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	queue <int> trucks;
	vector <pair<int, int> > trucks_time;
	for(int i = 0; i < truck_weights.size(); i++)
		trucks.push(truck_weights[i]);
	int tmp_weight = 0;
	trucks_time.push_back(make_pair(trucks.front(), 0));
	tmp_weight = trucks.front();
	trucks.pop();
	int time = 0;
	while(!trucks.empty() || !trucks_time.empty()){
//	for(int i = 0; i < 8; i++){
//		cout << trucks_time[0].first << ":" << trucks_time[0].second << "\n";
//		cout << time << "\n";
		if (trucks_time[0].second == bridge_length){
			tmp_weight -= trucks_time[0].first;
			trucks_time.erase(trucks_time.begin());
		}
		if (!trucks.empty() && weight - tmp_weight >= trucks.front()){
			trucks_time.push_back(make_pair(trucks.front(), 0));
			tmp_weight += trucks.front();
			trucks.pop();
		}
		for(int i = 0; i < trucks_time.size(); i++){
			if (trucks_time[i].second < bridge_length)
				trucks_time[i].second++;
		}
		time++;
	}
    return time;
}

int main(){
	vector<int> truck;
	truck.push_back(7);
	truck.push_back(4);
	truck.push_back(5);
	truck.push_back(6);
	cout << solution(2, 10, truck) << "\n";

}
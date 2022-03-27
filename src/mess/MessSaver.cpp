#include "MessSaver.h"

std::map<std::string, std::vector<float>> MessSaver::data = std::map<std::string, std::vector<float>>();

void MessSaver::add(std::string tag, float micros){

	if(data.count(tag) == 0){
		std::vector<float> vals = std::vector<float>();
		vals.push_back(micros);
		data.insert({tag,vals});	
	} else {
		data[tag].push_back(micros);
	}
	
	
}

void MessSaver::printAll(){
	for(auto& [tag, vec] : data){
		float avg = 0;
		for(float val : vec){
			avg += val;
		}
		avg /= vec.size();
		std::cout << "MESS: " << tag << ": " << avg << std::endl;
	}	
}


float MessSaver::get(std::string tag){
	
	if(data.count(tag)){
		auto vec = data[tag];
		float avg = 0;
		for(float val : vec){
			avg += val;
		}
		return avg / vec.size();
	} else {
		return -1;
	}

}

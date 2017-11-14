#pragma once
#include <gecode/search.hh>
#include <string>
#include "XCSP3PrintCallbacks.h"
#include "BuildGModel.h"
#include "BMFileParser.h"
#include "SAC1.h"
#include "CPUSolver.h"
#include <windows.h>
#include <io.h>  
using namespace cudacp;
using namespace Gecode;
using namespace std;


const string XPath = "BMPath.xml";
const int64_t TimeLimit = 1800000;
const string bmp_root = "E:\\Projects\\benchmarks\\xcsp\\";
const string bmp_ext = ".xml";
void getFilesAll(string path, vector<string>& files);


int main(const int argc, char ** argv) {

	if (argc <= 1) {
		std::cout << "no argument" << endl;
		return 0;
	}

	vector<string> files;
	getFilesAll(bmp_root + argv[1], files);

	int64_t sum_but = 0;
	int64_t sum_sact = 0;
	int64_t sum_st = 0;
	int64_t sum_nod = 0;
	int64_t num_sac = 0;
	int64_t num_sol = 0;
	int64_t num_has_sol = 0;
	int64_t num_bm = 0;

	for (const auto f : files) {
		cout << f << endl;
		++num_bm;

		HModel *hm = new HModel();
		GetHModel(f, hm);
		GModel* gm = new GModel();
		BuildGModel(hm, gm);

		SAC1 sac1(gm);
		Timer t;
		const bool result = sac1.enforce();
		const int64_t sac_time = t.elapsed();
		sum_sact += sac_time;

		if (result) {
			//sat sac
			num_sac++;
			const SearchStatistics statistics = StartSearch(gm, Heuristic::VRH_MIN_DOM, Heuristic::VLH_MIN, TimeLimit, sac_time);

			sum_but += statistics.build_time;

			if (!statistics.time_out) {
				sum_st += statistics.solve_time;
				++num_sol;
				num_has_sol += statistics.num_sol;
				sum_nod += statistics.nodes;
			}
		}

		delete hm;
		delete gm;
	}

	cout << "---------------sum---------------" << endl;
	cout << "SAC time = " << sum_sact <<
		" || SAC count = " << num_sac <<
		" || Build time = " << sum_but <<
		" || num solve = " << num_sol <<
		" || Solve time =" << sum_st <<
		" || nodes = " << sum_nod <<
		" || has solution = " << num_has_sol << endl;
	std::cout << "---------------------------------n2-avg---------------------------------" << endl;
	std::cout <<
		"sum time = " << sum_st / (num_sol) <<
		" || brs = " << sum_nod / (num_sol) <<
		" || time out = " << num_sac - num_sol << endl;
	return 0;
}

void getFilesAll(const string path, vector<string>& files) {
	//文件句柄 
	intptr_t  h_file = 0;
	//文件信息 
	struct _finddata_t fileinfo;
	string p;
	if ((h_file = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1) {
		do {
			if ((fileinfo.attrib & _A_SUBDIR)) {
				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0) {
					//files.push_back(p.assign(path).append("\\").append(fileinfo.name) );
					getFilesAll(p.assign(path).append("\\").append(fileinfo.name), files);
				}
			}
			else {
				files.push_back(p.assign(path).append("\\").append(fileinfo.name));
			}
		} while (_findnext(h_file, &fileinfo) == 0);
		_findclose(h_file);
	}
}
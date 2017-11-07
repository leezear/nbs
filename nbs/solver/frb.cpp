//#pragma once
//#include <gecode/search.hh>
//#include <string>
//#include "XCSP3PrintCallbacks.h"
//#include "BuildGModel.h"
//#include "BMFileParser.h"
//#include "SAC1.h"
//#include "CPUSolver.h"
//#include <windows.h>
//#include <io.h>  
//using namespace cudacp;
//using namespace Gecode;
//using namespace std;
////#define LOGFILE
//
//
//const string XPath = "BMPath.xml";
//const int64_t TimeLimit = 400000;
//const string bmp_root = "E:\\Projects\\benchmarks\\xcsp\\";
//const string bmp_ext = ".xml";
//void getFilesAll(string path, vector<string>& files);
//
//int main(const int argc, char ** argv) {
//
//	if (argc <= 1) {
//		std::cout << "no argument" << endl;
//		return 0;
//	}
//
//	vector<string> files;
//	getFilesAll(bmp_root + argv[1], files);
//	for (auto f : files) {
//
//		cout << f << endl;
//
//		HModel *hm = new HModel();
//		GetHModel(f, hm);
//		GModel* gm = new GModel();
//		BuildGModel(hm, gm);
//
//		SAC1 sac1(gm);
//		Timer t;
//		const bool result = sac1.enforce();
//		const int64_t sac_time = t.elapsed();
//		cout << "sac time = " << sac_time;
//		if (result) {
//
//			cout << " || sac! ";
//			const SearchStatistics statistics = StartSearch(gm, Heuristic::VRH_MIN_DOM, Heuristic::VLH_MIN, TimeLimit, sac_time);
//			cout << " || build time = " << statistics.build_time;
//
//			if (!statistics.time_out) {
//				cout << " || solve time = " << statistics.solve_time;
//				cout << " || solutions = " << statistics.num_sol;
//				cout << " || nodes = " << statistics.nodes;
//			}
//		}
//		else
//			cout << " || unsac! ";
//
//		cout << endl;
//		delete hm;
//		delete gm;
//	}
//	return 0;
//}
//
//void getFilesAll(string path, vector<string>& files) {
//	//文件句柄 
//	intptr_t  hFile = 0;
//	//文件信息 
//	struct _finddata_t fileinfo;
//	string p;
//	if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1) {
//		do {
//			if ((fileinfo.attrib & _A_SUBDIR)) {
//				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0) {
//					//files.push_back(p.assign(path).append("\\").append(fileinfo.name) );
//					getFilesAll(p.assign(path).append("\\").append(fileinfo.name), files);
//				}
//			}
//			else {
//				files.push_back(p.assign(path).append("\\").append(fileinfo.name));
//			}
//		} while (_findnext(hFile, &fileinfo) == 0);
//		_findclose(hFile);
//	}
//}
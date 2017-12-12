//#pragma once
//#include <gecode/search.hh>
//#include <fstream>
//#include <string>
//#include "XCSP3PrintCallbacks.h"
//#include "BuildGModel.h"
//#include "BMFileParser.h"
//#include "SAC1.h"
//#include "CPUSolver.h"
//#include <windows.h>
//using namespace cudacp;
//using namespace Gecode;
//using namespace std;
////#define LOGFILE
//
//
//const string XPath = "BMPath.xml";
//const int64_t TimeLimit = 400000;
//const string bmp_root = "E:/Projects/benchmarks/xcsp/";
//const string bmp_ext = ".xml";
////const string bmp_ext = "_X2.xml";
////const int num_bm = 10;
//int main(const int argc, char ** argv) {
//
//	if (argc <= 1) {
//		cout << "no argument" << endl;
//		return 0;
//	}
//	string num_bm_str = argv[2];
//	const int num_bm = atoi(argv[2]);
//
//
//	for (size_t i = 0; i < argc - 2; i++) {
//		int64_t sum_but = 0;
//		int64_t sum_sact = 0;
//		int64_t sum_st = 0;
//		int64_t sum_nod = 0;
//		int64_t num_sac = 0;
//		int64_t num_sol = 0;
//		int64_t num_has_sol = 0;
//
//		for (size_t j = 0; j < num_bm; j++) {
//			//	if (num_bm == 10) {
//			//		char num[2];
//			//		sprintf_s(num, "%d", j);
//			//		bm_path = bmp_root + argv[i + 1] + num + bmp_ext;
//			//		std::cout << bm_path << endl;
//			//	}
//
//			//	if (num_bm == 15) {
//			char num[3];
//			sprintf_s(num, "%02d", j);
//			const string bm_path = bmp_root + argv[i + 1] + num + bmp_ext;
//			std::cout << bm_path << endl;
//			//	}
//
//			HModel *hm = new HModel();
//			GetHModel(bm_path, hm);
//			GModel* gm = new GModel();
//			BuildGModel(hm, gm);
//
//			SAC1 sac1(gm);
//			Timer t;
//			const bool result = sac1.enforce();
//			const int64_t sac_time = t.elapsed();
//			sum_sact += sac_time;
//
//			if (result) {
//				//sat sac
//				num_sac++;
//				const SearchStatistics statistics = StartSearch(gm, Heuristic::VRH_MIN_DOM, Heuristic::VLH_MIN, TimeLimit, sac_time);
//				//const SearchStatistics statistics = StartSearch(hm, gm, Heuristic::VRH_MIN_DOM, Heuristic::VLH_MIN_INC);
//				//const SearchStatistics statistics = StartSearch(hm, gm, Heuristic::VRH_MIN_DOM, Heuristic::VLH_MAX_INC);
//				//const SearchStatistics statistics = StartSearch(hm, gm, Heuristic::VRH_MIN_DOM, Heuristic::VLH_MIN_DOM);
//				//const string  slv_str = (statistics.num_sol > 0) ? "SAT!!" : "UNSAT";
//
//				sum_but += statistics.build_time;
//
//				if (!statistics.time_out) {
//					sum_st += statistics.solve_time;
//					++num_sol;
//					num_has_sol += statistics.num_sol;
//					sum_nod += statistics.nodes;
//				}
//			}
//			delete hm;
//			delete gm;
//		}
//		cout << "---------------sum---------------" << endl;
//		cout << "SAC time = " << sum_sact <<
//			" || SAC count = " << num_sac <<
//			" || Build time = " << sum_but <<
//			" || num solve = " << num_sol <<
//			" || Solve time =" << sum_st <<
//			" || nodes = " << sum_nod <<
//			" || has solution = " << num_has_sol << endl;
//
//	}
//	return 0;
//}
//

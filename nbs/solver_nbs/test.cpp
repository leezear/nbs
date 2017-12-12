//#pragma once
//#include <gecode/search.hh>
//#include <gecode/driver.hh>
//#include <sstream>
//#include <fstream>
//#include <string>
//#include "XCSP3PrintCallbacks.h"
//#include "BuildGModel.h"
//#include "BMFileParser.h"
//#include "Timer.h"
//#include "SAC1.h"
//#include "CPUSolver.h"
//using namespace cudacp;
//using namespace Gecode;
//using namespace std;
////#define LOGFILE
//
//const int TimeLimit = 600000;
//const string x_path = "BMPath.xml";
//
//int main() {
//	string bm_path;
//	if (FindBMPath(x_path))
//		bm_path = _bm_path;
//	cout << bm_path << endl;
//	HModel *hm = new HModel();
//	GetHModel(bm_path, hm);
//	GModel* gm = new GModel();
//	BuildGModel(hm, gm);
//
//	//GModel* dgm = static_cast<GModel*>(gm->clone());
//	//Search::TimeStop ts(2000);
//	//Search::Options options;
//	//options.stop = &ts;
//	//branch(*dgm, dgm->vs, INT_VAR_SIZE_MIN(), INT_VALUES_MIN());
//	//DFS<GModel> ee(dgm, options);
//	//delete dgm;
//	//int find = -1;
//	//Timer t0;
//	//if (GModel* ss = ee.next()) {
//	//	ss->print();
//	//	find = 1;
//	//	cout << "nodes = " << ee.statistics().node << endl;
//	//	delete ss;
//	//}
//	//else 
//	//	find = 0;
//	//const int64_t gecode_solve_time = t0.elapsed();
//	//cout << "---------------gecode solving---------------" << endl;
//	//cout << "Gecode solve time = " << gecode_solve_time << endl;
//
//
//	SAC1 sac1(gm);
//	Timer t;
//	const bool result = sac1.enforce();
//	const int64_t sac_time = t.elapsed();
//	if (!result) {
//		cout << "UNSAC || SAC time = " << sac_time << endl;
//		cout << "--------------------end---------------------" << endl;
//		delete hm;
//		delete gm;
//		return 0;
//	}
//
//	cout << "------------------modeling------------------" << endl;
//	const SearchStatistics statistics = StartSearch(gm, Heuristic::VRH_MIN_DOM, Heuristic::VLH_MIN, TimeLimit, sac_time);
//	const string  slv_str = (statistics.num_sol > 0) ? "SAT!!" : "UNSAT";
//	delete hm;
//	delete gm;
//	cout << "SAC time = " << sac_time << "|| Build time = " << statistics.build_time << endl;
//	cout << "------------------solving-------------------" << endl;
//	cout << slv_str << "|| Solve time = " << statistics.solve_time << "|| nodes = " << statistics.nodes << endl;
//	cout << "------------------sleeping------------------" << endl;
//
//	return 0;
//}
//

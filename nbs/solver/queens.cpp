//#pragma once
//#include <gecode/search.hh>
//#include <gecode/driver.hh>
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
//const int time_limit = 600000;
//const string x_path = "BMPath.xml";
//
//int main(const int argc, char ** argv) {
//	if (argc <= 1) {
//		cout << "no argument" << endl;
//		return 0;
//	}
//
//	const int n = atoi(argv[1]);
//	GModel* gm = new GModel();
//	BuildQueens(gm, n, PROP_BINARY, IPL_SPEED);
//
//	gm->print();
//	//delete gm;
//
//	GModel* dgm = static_cast<GModel*>(gm->clone());
//	Search::TimeStop ts(2000);
//	Search::Options options;
//	options.stop = &ts;
//	//branch(*dgm, dgm->vs, INT_VAR_SIZE_MIN(), INT_VALUES_MIN());
//	branch(*dgm, dgm->vs, INT_VAR_NONE(), INT_VALUES_MIN());
//	DFS<GModel> ee(dgm, options);
//	delete dgm;
//	int find = -1;
//	Timer t0;
//	if (GModel* ss = ee.next()) {
//		ss->print();
//		find = 1;
//		cout << "nodes = " << ee.statistics().node << endl;
//		cout << "time = " << t0.elapsed() << endl;
//		delete ss;
//	}
//	else
//		find = 0;
//	const int64_t gecode_solve_time = t0.elapsed();
//	cout << "---------------gecode solving---------------" << endl;
//	cout << "Gecode solve time = " << gecode_solve_time << endl;
//
//
//	SAC1 sac1(gm);
//	Timer t;
//	const bool result = sac1.enforce();
//	const int64_t sac_time = t.elapsed();
//	if (!result) {
//		cout << "UNSAC || SAC time = " << sac_time << endl;
//		cout << "--------------------end---------------------" << endl;
//		delete gm;
//		return 0;
//	}
//
//	cout << "------------------modeling------------------" << endl;
//	const SearchStatistics statistics = StartSearch(gm, Heuristic::VRH_MIN_DOM, Heuristic::VLH_MIN, time_limit);
//	const string  slv_str = (statistics.num_sol > 0) ? "SAT!!" : "UNSAT";
//	delete gm;
//	cout << "SAC time = " << sac_time << "|| Build time = " << statistics.build_time << endl;
//	cout << "------------------solving-------------------" << endl;
//	cout << slv_str << "|| Solve time = " << statistics.solve_time << "|| nodes = " << statistics.nodes << endl;
//	cout << "------------------sleeping------------------" << endl;
//
//	return 0;
//}
//

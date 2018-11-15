#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ostream& operator<<(ostream& os, const vector<size_t>& lengthInfo) {
	for(size_t i=1; i<lengthInfo.size(); ++i) {
		os << lengthInfo[i] << " ";
	}
	os << endl;
	return os;
}

class dijkstra {
private:
	typedef vector< vector<size_t> > edgeInfo_t;
	typedef vector<size_t> length_t;
	typedef vector<size_t> node_t;
	typedef vector<bool> visit_t;
private:
	edgeInfo_t edgeInfo;
	length_t dist;
	node_t prev;
	visit_t visit;
private:
	void initEdgeInfo(size_t N) {
		edgeInfo = edgeInfo_t(N, length_t(N, -1) );
	}
	void initLength(size_t N) {
		dist = length_t(N, -1);
	}
	void initVisit(size_t N) {
		visit = visit_t(N, false);
	}
	void initPrev(size_t N) {
		prev = node_t(N, -1);
	}	
	istream& getEdgeInfo(istream& is, size_t N) {
		int beg, end, len;
		for(size_t i=0; i<N; ++i) {
			is >> beg >> end >> len;
			edgeInfo[beg][end] = len;
			edgeInfo[end][beg] = len;
		}
		return is;
	}
	size_t getMinimumNode() const {
		size_t retNode = -1;
		size_t min = -1;
		for(size_t i=1; i<dist.size(); ++i) {
			if(visit[i] == false && dist[i] < min) {
				retNode = i;
				min = dist[i];
			}
		}
		return retNode;
	}
	bool isEnd(void) const {
		for(size_t i=1; i<visit.size(); ++i) {
			if(visit[i] == false)
				return false;
		}
		return true;
	}
public:
	ostream& print(ostream& os) const {
		os << "edge" << endl;;
		for(size_t i=1; i<edgeInfo.size(); ++i) {
			for(size_t j=1; j<edgeInfo[i].size(); ++j) {
				os << i << " " << j << " " << edgeInfo[i][j] << endl;
			}
		}
		
		os << "length" << endl;
		os << dist;
	
		return os;
	}
	istream& init(istream& is) {
		size_t N;
		is >> N;
		initEdgeInfo(N+1);
		initLength(N+1);
		initPrev(N+1);
		initVisit(N+1);
		is >> N;
		getEdgeInfo(is, N);
		return is;
	}
	const length_t& getMinimumShortestPathTree(void) const {
		return dist;
	}
	void makeMinimumShortestPathTree(void) {
		dist[1] = 0;
		while(!isEnd()) {
			size_t node = getMinimumNode();
			if(node == -1)
				break;
			visit[node] = true;
			
			// neighbor update
			for(size_t i=1; i<dist.size(); ++i) {
				if(visit[i] == false && edgeInfo[node][i] != -1 && dist[i] > edgeInfo[node][i] + dist[node]) {
					dist[i] = edgeInfo[node][i] + dist[node];
					prev[i] = node;
				}
			}
		}
	}
};

int main(void) {
	ifstream ifs("dijkstra.txt");
	dijkstra myDijkstra;
	myDijkstra.init(ifs);
	myDijkstra.makeMinimumShortestPathTree();
	//myDijkstra.print(cout);
	cout << myDijkstra.getMinimumShortestPathTree();
	
	return 0;
}

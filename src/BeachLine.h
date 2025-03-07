#pragma once

#include "RBTree.h"

namespace Voronoi {
	struct Site;
	struct Edge;
	struct CircleEvent;

	struct BeachSection {
		Site *site;
		Edge *edge;
		treeNode<CircleEvent> *circleEvent;

		BeachSection() : site(nullptr), edge(nullptr), circleEvent(nullptr) {};
		~BeachSection() {};
		BeachSection(Site *_site) : site(_site), edge(nullptr), circleEvent(nullptr) {};
	};
}
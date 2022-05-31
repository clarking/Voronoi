#pragma once

#include "RBTree.h"
#include "BeachLine.h"

namespace Voronoi {

	struct Site;
	struct BeachSection;

	struct CircleEvent {
		Site *site;
		double x;
		double y;
		double yCenter;
		treeNode<BeachSection> *beachSection;

		CircleEvent() {};
		~CircleEvent() {};
		CircleEvent(Site *_site, double _x, double _y, double _yCenter, treeNode<BeachSection> *_section) {
			site = _site;
			x = _x;
			y = _y;
			yCenter = _yCenter;
			beachSection = _section;
		}
	};

	struct CircleEventQueue {
		treeNode<CircleEvent> *firstEvent;
		RBTree<CircleEvent> eventQueue;

		CircleEventQueue() : firstEvent(nullptr) {};
		~CircleEventQueue() {};

		void addCircleEvent(treeNode<BeachSection> *section);

		void removeCircleEvent(treeNode<BeachSection> *section);
	};
}
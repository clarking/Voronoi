#pragma once

#include "RBTree.h"
#include "CircleEventQueue.h"
#include "BeachLine.h"
#include "Diagram.h"
#include <vector>

namespace Voronoi {

	struct BoundingBox {
		double xL;
		double xR;
		double yB;
		double yT;

		BoundingBox() {};
		BoundingBox(double xmin, double xmax, double ymin, double ymax) :
			xL(xmin), xR(xmax), yB(ymin), yT(ymax) {};
	};

	class VoronoiGenerator {
	public:
		VoronoiGenerator() : circleEventQueue(nullptr), siteEventQueue(nullptr), beachLine(nullptr) {};
		~VoronoiGenerator() {};

		Diagram *compute(std::vector <Point2> &sites, BoundingBox bbox);

		Diagram *relax();

	private:
		Diagram *diagram;
		CircleEventQueue *circleEventQueue;
		std::vector<Point2 *> *siteEventQueue;
		BoundingBox boundingBox;

		void printBeachLine();

		//BeachLine
		RBTree<BeachSection> *beachLine;

		treeNode<BeachSection> *addBeachSection(Site *site);

		inline void detachBeachSection(treeNode<BeachSection> *section);

		void removeBeachSection(treeNode<BeachSection> *section);

		double leftBreakpoint(treeNode<BeachSection> *section, double directrix);

		double rightBreakpoint(treeNode<BeachSection> *section, double directrix);
	};

	inline void VoronoiGenerator::detachBeachSection(treeNode<BeachSection> *section) {
		circleEventQueue->removeCircleEvent(section);
		beachLine->removeNode(section);
	}

}
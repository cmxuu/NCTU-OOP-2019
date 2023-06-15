//********************************************
// Student Name			: ½²»Ê¸©
// Student ID			: 0812203
// Student Email Address: minghsuan.am08@nctu.edu.tw
//********************************************
//
// Instructor: Sai-Keung WONG
// Email:	cswingo@cs.nctu.edu.tw
//			wingo.wong@gmail.com
//
// National Chiao Tung University, Taiwan
// Computer Science
// Date: 2019/04/09
//
#include <iostream>
#include <fstream>
#include "mySystem_GraphSystem.h"
#include <time.h>

using namespace std;

#define GRAPH_FILE_NAME "graph.txt"

int Param::GRAPH_MAX_NUM_NODES = 1000;
int Param::GRAPH_MAX_NUM_EDGES = 1000;
int Param::Export_Count_DrawingFX = 300;

GRAPH_SYSTEM::GRAPH_SYSTEM( )
{
    mFlgAutoNodeDeletion = false;
    mExport_Count_DrawingFX = 0;

    initMemoryPool();
    createDefaultGraph();
}

void GRAPH_SYSTEM::initMemoryPool( )
{
    mMaxNumNodes = Param::GRAPH_MAX_NUM_NODES;
    mMaxNumEdges = Param::GRAPH_MAX_NUM_EDGES;

    mNodeArr_Pool = new GRAPH_NODE[mMaxNumNodes];
    mEdgeArr_Pool = new GRAPH_EDGE[mMaxNumEdges];

    mCurNumOfActiveNodes = 0;
    mCurNumOfActiveEdges = 0;
    mActiveNodeArr = new int[mMaxNumNodes];
    mActiveEdgeArr = new int[mMaxNumEdges];

    mFreeNodeArr = new int[mMaxNumNodes];
    mFreeEdgeArr = new int[mMaxNumEdges];
    //
    for ( int i = 0; i < mMaxNumNodes; ++i ) {
        mNodeArr_Pool[ i ].id = i;
    }
    for ( int i = 0; i < mMaxNumEdges; ++i ) {
        mEdgeArr_Pool[ i ].id = i;
    }
    //
    reset( );
}

void GRAPH_SYSTEM::reset( )
{
    stopAutoNodeDeletion();

    //mNumPoints_DoubleCircles = 0;

    mCurNumOfActiveNodes = 0;
    mCurNumOfActiveEdges = 0;

    mCurNumOfFreeNodes = mMaxNumNodes;
    mCurNumOfFreeEdges = mMaxNumEdges;

    for ( int i = 0; i < mCurNumOfFreeNodes; ++i ) {
        mFreeNodeArr[i] = mMaxNumNodes - i - 1;
    }
    for ( int i = 0; i < mCurNumOfFreeEdges; ++i ) {
        mFreeEdgeArr[i] = mMaxNumEdges - i - 1;
    }

    mPassiveSelectedNode = 0;
    mSelectedNode = 0;
}

GRAPH_NODE *GRAPH_SYSTEM::getFreeNode( ) 
{
    if ( mCurNumOfFreeNodes == 0 ) return 0;
    --mCurNumOfFreeNodes;
    int id = mFreeNodeArr[ mCurNumOfFreeNodes ];
    GRAPH_NODE *n = &mNodeArr_Pool[id];
    mActiveNodeArr[mCurNumOfActiveNodes] = id;
    n->dynamicID = mCurNumOfActiveNodes;
    ++mCurNumOfActiveNodes;
    return n;
}

GRAPH_EDGE *GRAPH_SYSTEM::getFreeEdge( )
{
    if (mCurNumOfFreeEdges == 0) return 0;
    --mCurNumOfFreeEdges;
    int id = mFreeEdgeArr[mCurNumOfFreeEdges];
    GRAPH_EDGE* e = &mEdgeArr_Pool[id];
    mActiveEdgeArr[mCurNumOfActiveEdges] = id;
    e->dynamicID = mCurNumOfActiveEdges;
    ++mCurNumOfActiveEdges;
    return e;

}

void GRAPH_SYSTEM::createDefaultGraph( )
{
    cout << "here"<< endl;
    reset( );

    int n_0 = addNode(0.0, 0.0, 0.0);
    cout << "n_0:"<< n_0 << endl;
    int n_1 = addNode(5.0, 0.0, 0.0);
    cout << "n_1:" << n_1 << endl;
    int n_2 = addNode(0.0, 0.0, 5.0);
    cout << "n_2:"<< n_2 << endl;

    addEdge(n_0, n_1);
    addEdge(n_1, n_2);
}

void GRAPH_SYSTEM::createNet_Horizontal( int nx, int ny )
{
    reset( );

    float dx = 5.0;
    float dz = 5.0;
    vector<int> id;
}

void GRAPH_SYSTEM::createNet_Vertical( int nx, int ny )
{
    reset( );

    float dx = 5.0;
    float dz = 5.0;
    vector<int> id;
}

void GRAPH_SYSTEM::createRandomGraph( int nx, int ny )
{
    reset( );

    float dx = 5.0;
    float dz = 5.0;

}

void GRAPH_SYSTEM::createRadialGraph( int nx, int ny )
{
    reset( );

    float dx = 5.0;
    float dz = 5.0;

}

void GRAPH_SYSTEM::createRandomGraph_DoubleCircles(int n)
{
    reset( );

    //n = 36;
    float dx = 5.0;
    float dz = 5.0;
    float r = 15; // radius
    float d = 10; // layer distance
    float offset_x = 15.;
    float offset_z = 15.;
    vector<int> id;
    id.resize(2 * n + 1);

    //Node: 1~n / n+1~2n
    for (int i = 1; i <= n; i++)
    {
        id[i] = addNode((r)*cos(i * (360.0 / n) / 180 * acos(-1.0)) + offset_x, 0.0, (r)*sin(i * (360.0 / n) / 180 * acos(-1.0)) + offset_z);
        id[n + i] = addNode((r + d) * cos(i * (360.0 / n) / 180 * acos(-1.0)) + offset_x, 0.0, (r + d) * sin(i * (360.0 / n) / 180 * acos(-1.0)) + offset_z);
    }

    //Edge
    for (int i = 1; i <= n; i++)
    {
        int RandIndex = rand() % 5 - 2;
        if (RandIndex + i < 1) RandIndex += n;
        else if (RandIndex + i > n) RandIndex -= n;
        addEdge(id[i], id[RandIndex + n + i]);
    }
}

void GRAPH_SYSTEM::createNet_Circular( int n, int num_layers )
{
    reset( );

    float dx = 360.0 / n;
    float dz = 360.0 / n;
    float r = 5; // radius
    float d = 5; // layer distance 
    float offset_x = 15.;
    float offset_z = 15.;
    vector<int> id;
    id.resize(n * (num_layers + 1) + 1);
    
    //Node
    for (int i = 0; i < num_layers + 1; i++)
        for (int j = 0; j < n; j++)
            id[n * i + j] = addNode((r + i * d) * cos(j * dx / 180 * acos(-1.0)) + offset_x, 0.0, (r + i * d) * sin(j * dz / 180 * acos(-1.0)) + offset_z);
    
    //Edge
    for (int i = 0; i < num_layers; i++)
        for (int j = 0; j < n; j++)
        {
            addEdge(id[n * i + j], id[n * (i + 1) + j]);
            if (j + 1 != 12)
                addEdge(id[n * i + j], id[n * i + j + 1]);
            else
                addEdge(id[n * i + j], id[n * i]);
        }

}
void GRAPH_SYSTEM::createNet_Square( int n, int num_layers )
{
    reset( );

    float dx = 5.0;
    float dz = 5.0;
    float r = 5; // radius
    float d = 5; // layer distance 
    float offset_x = 5.;
    float offset_z = 5.;
    int max_num = n + 2 * (num_layers - 1);
    vector<int> id;
    id.resize(max_num * max_num);

    //Node
    for (int i = 0; i < max_num; i++)
        for (int j = 0; j < max_num; j++)
            if (!(i >= num_layers && i < max_num - num_layers && j >= num_layers && j < max_num - num_layers))
                id[max_num * i + j] = addNode(offset_x + j * r, 0.0, offset_z + i * d);
    
    //Horizontal Edge
    for (int i = 0; i < max_num; i++)
        for (int j = 0; j < max_num-1; j++)
            if ((i<num_layers )|| (i>=max_num - num_layers) ||( i>= num_layers && num_layers< max_num - num_layers && (j < num_layers-1 || j >= max_num - num_layers)))
                addEdge(id[max_num * i + j], id[max_num * i + j+1]);

    //Straight Edge
    for (int i = 0; i < max_num - 1; i++)
        for (int j = 0; j < max_num; j++)
            if ((i < num_layers-1) || (i >= max_num - num_layers) || (i >= num_layers-1 && num_layers < max_num - num_layers && (j < num_layers || j >= max_num - num_layers)))
                addEdge(id[max_num * i + j], id[max_num * (i + 1) + j]);

}
void GRAPH_SYSTEM::createNet_RadialCircular( int n ) {

    reset( );

    float offset_x = 15.0;
    float offset_z = 15.0;
    float r = 15; // radius
    vector<int> id;
    id.resize(n + 1);

    //Node + Edge
    id[0] = addNode(offset_x, 0.0, offset_z);
    for (int i = 1; i <= n; i++)
    {
        id[i] = addNode((r)*cos(i * (360.0 / n) / 180 * acos(-1.0)) + offset_x, 0.0, (r)*sin(i * (360.0 / n) / 180 * acos(-1.0)) + offset_z);
        addEdge(id[0], id[i]);
    }
}

int GRAPH_SYSTEM::addNode( float x, float y, float z, float r )
{
    GRAPH_NODE* g;
    g = getFreeNode();
    if (g == 0)
        return -1;
    g->p = vector3(x, y, z);
    g->r = r;
    g->edgeID.clear();
    return g->id;
}

int GRAPH_SYSTEM::addEdge( int nodeID_0, int nodeID_1 )
{
    GRAPH_EDGE* e;
    e = getFreeEdge();
    if (e == 0)
        return -1;
    e->nodeID[0] = nodeID_0;
    e->nodeID[1] = nodeID_1;
    mNodeArr_Pool[nodeID_0].edgeID.push_back(e->id);
    mNodeArr_Pool[nodeID_1].edgeID.push_back(e->id);
    return e->id;
}

void GRAPH_SYSTEM::askForInput( )
{
    cout << "GRAPH_SYSTEM" << endl;
    cout << "Key usage:" << endl;
    cout << "1: create a default graph" << endl;
    cout << "2: create nodes arranged in circles" << endl;
    cout << "3: create nodes arranged in squares" << endl;
    cout << "4: create nodes arranged in a circle and one node at center" << endl;
    cout << "5: create nodes arranged in 2 circles with random edges" << endl;
    cout << "Delete: delete a node and all the edges attached at it" << endl;
    cout << "Spacebar: unselect the selected node" << endl;
    cout << " " << endl;
    cout << "Use the mouse to select nodes and add edges" << endl;
    cout << "Click the left button to select/unselect or create an edge" << endl;
    cout << " " << endl;
    cout << "A selected node is highlighted as red." << endl;

}

GRAPH_NODE *GRAPH_SYSTEM::findNearestNode( double x, double z, double &cur_distance2 ) const
{
    if (mCurNumOfActiveNodes == 0)  return 0;
    GRAPH_NODE* n;
    cur_distance2 = -1;
    double distance;
    for (int i = 0; i < mCurNumOfActiveNodes; i++)
    {
        distance = pow(mNodeArr_Pool[mActiveNodeArr[i]].p.x - x, 2) + pow(mNodeArr_Pool[mActiveNodeArr[i]].p.z - z, 2);
        if (distance < cur_distance2 || cur_distance2 < 0)
        {
            cur_distance2 = distance;
            n = &mNodeArr_Pool[mActiveNodeArr[i]];
        }
    }
    return n;
}

void GRAPH_SYSTEM::clickAt(double x, double z)
{
    double cur_d2;
    GRAPH_NODE *n = findNearestNode( x, z, cur_d2 );
    if ( n == 0 ) {
        mSelectedNode = 0;
        return;
    }
    if ( cur_d2 > n->r*n->r ) {
        mSelectedNode = 0;
        return;

    }
    if ( mSelectedNode == n ) {
        mSelectedNode = 0;
        return;
    }
    if ( mSelectedNode != 0 ) {
        addEdge( mSelectedNode->id, n->id );
        mSelectedNode = 0;
        return;
    }
    mSelectedNode = n;
}

void GRAPH_SYSTEM::deleteEdge( int edgeID )
{
    if (mCurNumOfActiveEdges <= 0) return;

    GRAPH_EDGE* e = &mEdgeArr_Pool[edgeID];

    //delete edgeID from connect node
    removeEdgeFromNode(e, e->nodeID[0]);
    removeEdgeFromNode(e, e->nodeID[1]);

    //move to free edge
    mFreeEdgeArr[mCurNumOfFreeEdges] = edgeID;  
    mCurNumOfFreeEdges++;

    //delete from active edge
    GRAPH_EDGE* l = &mEdgeArr_Pool[mActiveEdgeArr[mCurNumOfActiveEdges - 1]];
    int dynamicID = e->dynamicID;
    mActiveEdgeArr[dynamicID] = mActiveEdgeArr[mCurNumOfActiveEdges - 1];
    l->dynamicID = dynamicID;
    mCurNumOfActiveEdges--;

}

void GRAPH_SYSTEM::removeEdgeFromNode( const GRAPH_EDGE *e, int nodeID )
{
    GRAPH_NODE *n = &mNodeArr_Pool[ nodeID ];
    int ID = e->id;
    int size = n->edgeID.size();
    for (int i = 0; i < size; i++)
    {
        if (n->edgeID[i] == ID)
        {
            n->edgeID[i] = n->edgeID.back();
            n->edgeID.pop_back();
            break;
        }
    }
}

void GRAPH_SYSTEM::deleteEdgesOfNode( int nodeID )
{
    GRAPH_NODE *n  = &mNodeArr_Pool[ nodeID ];
    int size = n->edgeID.size();
    for (int i = 0; i <size ; i++)
    {
        deleteEdge(n->edgeID[i]);
    }
}

void GRAPH_SYSTEM::deleteNode( int nodeID ) 
{
    if ( mCurNumOfActiveNodes <= 0 ) return;

    //delete edge connected by node
    deleteEdgesOfNode(nodeID);

    //move to free node
    GRAPH_NODE *n = &mNodeArr_Pool[ nodeID ];
    mFreeNodeArr[mCurNumOfFreeNodes] = nodeID;
    mCurNumOfFreeNodes++;

    //delete from active node
    GRAPH_NODE* l = &mNodeArr_Pool[mActiveNodeArr[mCurNumOfActiveNodes - 1]];
    int dynamicID = n->dynamicID;
    mActiveNodeArr[dynamicID] = mActiveNodeArr[mCurNumOfActiveNodes - 1];
    l->dynamicID = dynamicID;
    mCurNumOfActiveNodes--;

}

void GRAPH_SYSTEM::deleteSelectedNode(  ) {
    if ( mSelectedNode == 0 ) return;
    deleteNode( mSelectedNode->id );
    deleteEdgesOfNode( mSelectedNode->id );
    mSelectedNode = 0;
    mPassiveSelectedNode = 0;
}

bool GRAPH_SYSTEM::isSelectedNode( ) const
{
    return mSelectedNode != 0;
}

void GRAPH_SYSTEM::getInfoOfSelectedPoint( double &r, vector3 &p ) const
{
    if ( isSelectedNode( ) == false ) return;
    r = mSelectedNode->r;
    p = mSelectedNode->p;
}



void GRAPH_SYSTEM::handleKeyPressedEvent( unsigned char key )
{
    
    switch( key ) 
    {
    case 127: // delete
        mFlgAutoNodeDeletion = false;
        deleteSelectedNode( );
        break;
    case '1':
        mFlgAutoNodeDeletion = false;
        createDefaultGraph( );
        mSelectedNode = 0;
        break;
    case '2':
        mFlgAutoNodeDeletion = false;
        createNet_Circular(12, 3);
        mSelectedNode = 0;

        break;
    case '3':
        mFlgAutoNodeDeletion = false;
        createNet_Square(15, 4);
        mSelectedNode = 0;
        break;
    case '4':
        mFlgAutoNodeDeletion = false;
        createNet_RadialCircular(24);
        mSelectedNode = 0;
        break;
    case '5':
        mNumPoints_DoubleCircles = 24;
        mFlgAutoNodeDeletion = false;
        createRandomGraph_DoubleCircles(mNumPoints_DoubleCircles);
        mSelectedNode = 0;
        break;
    case '<':
        mNumPoints_DoubleCircles--;
        if (mNumPoints_DoubleCircles<3) 
            mNumPoints_DoubleCircles = 3;
        mFlgAutoNodeDeletion = false;
        createRandomGraph_DoubleCircles(mNumPoints_DoubleCircles);
        mSelectedNode = 0;
        break;
    case '>':
        mNumPoints_DoubleCircles++;
        if (mNumPoints_DoubleCircles> 36) 
            mNumPoints_DoubleCircles = 36;
        mFlgAutoNodeDeletion = false;
        createRandomGraph_DoubleCircles(mNumPoints_DoubleCircles);
        mSelectedNode = 0;
        break;
    case ' ':
        mFlgAutoNodeDeletion = false;
        mSelectedNode = 0;
        break;
    case 'd':
    {
        mFlgAutoNodeDeletion = !mFlgAutoNodeDeletion;
        break;
    }
    case 'e':
        mFlgAutoNodeDeletion = false;
        mSelectedNode = 0;
        exportGraph( GRAPH_FILE_NAME );
        break;
    }
}

void GRAPH_SYSTEM::handlePassiveMouseEvent( double x, double z )
{
    double cur_d2;
    GRAPH_NODE *n = findNearestNode( x, z, cur_d2 );
    if ( n == 0 ) return;
    if ( cur_d2 > n->r*n->r ) {
        mPassiveSelectedNode = 0;
        return;
    }
    mPassiveSelectedNode = n;
}

int GRAPH_SYSTEM::getNumOfNodes( ) const
{
    return mCurNumOfActiveNodes;
}

int GRAPH_SYSTEM::getNodeID( int nodeIndex ) const
{
    int nodeID = mActiveNodeArr[ nodeIndex ];
    return nodeID;
}

int GRAPH_SYSTEM::getNodeInfo( int nodeIndex, double &r, vector3 &p ) const
{
    int nodeID = mActiveNodeArr[ nodeIndex ];
    GRAPH_NODE *n = &mNodeArr_Pool[ nodeID ];
    r = n->r;
    p = vector3(n->p.x, n->p.y, n->p.z);
    return nodeID;
}

int GRAPH_SYSTEM::getNumOfEdges( ) const
{
    return mCurNumOfActiveEdges;
}

int GRAPH_SYSTEM::getEdgeID( int edgeIndex ) const
{
    int edgeID = mActiveEdgeArr[ edgeIndex ];
    return edgeID;
}

int GRAPH_SYSTEM::getNodeIDOfEdge( int edgeIndex, int nodeIndex ) const
{
    int edgeID = mActiveEdgeArr[ edgeIndex ];
    GRAPH_EDGE *e = &mEdgeArr_Pool[ edgeID ];
    return e->nodeID[nodeIndex];
}

vector3 GRAPH_SYSTEM::getNodePositionOfEdge( int edgeIndex, int nodeIndex ) const
{
    int nodeID = getNodeIDOfEdge(edgeIndex, nodeIndex);
    GRAPH_NODE* n = &mNodeArr_Pool[nodeID];
    vector3 p = vector3(n->p.x, n->p.y, n->p.z);
    return p;
}

void GRAPH_SYSTEM::stopAutoNodeDeletion()
{
    mFlgAutoNodeDeletion = false;
}

//
// For every frame, update( ) function is called.
//
// 
void GRAPH_SYSTEM::update( )
{
    if (!mFlgAutoNodeDeletion|| mCurNumOfActiveNodes==0)
    {
        mFlgAutoNodeDeletion = false;
        return;
    }
    
    deleteNode(mActiveNodeArr[mCurNumOfActiveNodes-1]);
    Sleep(250);
    mSelectedNode = 0;
    mPassiveSelectedNode = 0;
}

//
// Export each node to the file steam fObj
// node_ID x y z
// The work flow
//
// Get the number of nodes
// For each node do
//    Get the node ID of the node
//    Get the radius and position of the node
//    Save the node information to the file stream
//
// Return
//
void GRAPH_SYSTEM::emitNodes( std::fstream *fObj ) const
{
    GRAPH_NODE* n;
    int num = getNumOfNodes( );
    for (int i = 0; i < num; i++)
    {
        n = &mNodeArr_Pool[mActiveNodeArr[i]];
        *fObj << n->id << "\t" << n->p.x << "\t" << n->p.y << "\t" << n->p.z << endl;
    }
}

//
// Export each edge to the file stream fObj
// edge_ID node0_ID node1_ID
//
// The work flow
//
// Get the number of edges
// For each edge do
//    Get the edge ID of the edge
//    Get the node ID of the first node of the edge
//    Get the node ID of the second node of the edge
//    Save the edge information to the file stream
//
// Return
//
void GRAPH_SYSTEM::emitEdges( std::fstream *fObj ) const
{
    GRAPH_EDGE* e;
    int num = getNumOfEdges( );
    for (int i = 0; i < num; i++)
    {
        e = &mEdgeArr_Pool[mActiveEdgeArr[i]];
        *fObj << e->id << "\t" << e->nodeID[0] << "\t" << e->nodeID[1] << endl;
    }
}

//
// The work flow
// Create a file stream object or pointer, fObj
// Use fObj to open a file for text output
// Check if the file is opened successfully
// If the file cannot be opened, show an error message and return
// Otherwise, go on to process the following steps.
// Get the number of nodes, n
// Get the number of edges, m
// Save n to fObj
// Save m to fObj
// Call emitNodes
// Call emitEdges
// Close the file
// Delete the object fObj if necessary
// Show a message
//
void GRAPH_SYSTEM::exportGraph(const std::string &fileName) const
{
    cout << "BEGIN GRAPH_SYSTEM::exportGraph" << endl;

    //////////////////////////////////////
    // DO NOT DELETE THE FOLLOWING LINE
    mExport_Count_DrawingFX = Param::Export_Count_DrawingFX;
    //////////////////////////////////////

    cout << "Filename:" << fileName << endl;
    fstream *fObj = new fstream;

    fObj->open(fileName, ios::out);
    if (!fObj)
    {
        cout << "ERROR" << endl;
        return;
    }
    
    *fObj << mCurNumOfActiveNodes << endl;
    *fObj << mCurNumOfActiveEdges << endl;
    emitNodes(fObj);
    emitEdges(fObj);

    fObj->close();

    cout << "END GRAPH_SYSTEM::exportGraph" << endl;

}


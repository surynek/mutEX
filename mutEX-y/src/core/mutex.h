/*============================================================================*/
/*                                                                            */
/*                                                                            */
/*                              mutEX 0-007_void                              */
/*                                                                            */
/*                      (C) Copyright 2020 Pavel Surynek                      */
/*                                                                            */
/*                http://www.surynek.net | <pavel@surynek.net>                */
/*       http://users.fit.cvut.cz/surynek | <pavel.surynek@fit.cvut.cz>       */
/*                                                                            */
/*============================================================================*/
/* mutex.h / 0-007_void                                                       */
/*----------------------------------------------------------------------------*/
//
// Mutex network related data structures and algorithms.
//
/*----------------------------------------------------------------------------*/

#ifndef __MUTEX_H__
#define __MUTEX_H__

#include <vector>
#include <list>
#include <set>
#include <map>

#include "result.h"

#include "common/types.h"


using namespace mutEX;


/*----------------------------------------------------------------------------*/

namespace mutEX
{

   
/*----------------------------------------------------------------------------*/
// sNetwork

    class sNetwork
    {
    public:
	typedef std::vector<sInt_32> NodeIDs_vector;
	typedef std::vector<sInt_32> ClusterIDs_vector;
	typedef std::set<sInt_32> ClusterIDs_set;
	typedef std::map<sInt_32, sInt_32> ClusterLinks_map;
	typedef std::vector<NodeIDs_vector> Neighbors_vector;
	
	typedef std::vector<NodeIDs_vector> Clusters_vector;
	typedef std::vector<ClusterIDs_vector> ClusterMapping_vector;	

	typedef std::vector<ClusterLinks_map> ClusterLinking_vector;
    public:
	sNetwork() { /* network */ };
	sNetwork(sInt_32 N_nodes);

	bool add_Link(sInt_32 node_u_id, sInt_32 node_v_id);
	
	bool increment_ClusterLink(sInt_32 cluster_U_id, sInt_32 cluster_V_id);

    public:
	virtual void to_Screen(const sString &indent = "") const;
	virtual void to_Stream(FILE *fw, const sString &indent = "") const;	
	
    public:
	Neighbors_vector m_node_Neighbors;
	
	Clusters_vector m_node_Clustering;	
	ClusterMapping_vector m_cluster_Mapping;

	ClusterLinking_vector m_cluster_Linking;	
    };



/*----------------------------------------------------------------------------*/

} // namespace mutEX

#endif /* __MUTEX_H__ */

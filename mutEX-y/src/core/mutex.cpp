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
/* mutex.cpp / 0-007_void                                                     */
/*----------------------------------------------------------------------------*/
//
// Mutex network related data structures and algorithms.
//
/*----------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "config.h"
#include "compile.h"
#include "defs.h"
#include "result.h"

#include "common/types.h"
#include "core/graph.h"
#include "core/mutex.h"

using namespace mutEX;


/*----------------------------------------------------------------------------*/

namespace mutEX
{


/*----------------------------------------------------------------------------*/
// sNetwork

    sNetwork::sNetwork(sInt_32 N_nodes)
    {
	m_node_Clustering.resize(N_nodes);
	m_cluster_Mapping.resize(N_nodes);

	sInt_32 node_id = 0;
		    
	for (sInt_32 cluster_id = 0; cluster_id < N_nodes; ++cluster_id)
	{
	    m_node_Clustering[cluster_id].push_back(node_id);
	    m_cluster_Mapping[node_id].push_back(cluster_id);
	    ++node_id;
	}

	m_node_Neighbors.resize(N_nodes);
	m_cluster_Linking.resize(N_nodes);
    }


/*----------------------------------------------------------------------------*/
    
    bool sNetwork::add_Link(sInt_32 node_u_id, sInt_32 node_v_id)
    {
	sASSERT(node_u_id >= 0 && node_u_id < m_node_Neighbors.size());
	sASSERT(node_v_id >= 0 && node_v_id < m_node_Neighbors.size());	

	if (m_node_Neighbors[node_u_id].size() < m_node_Neighbors[node_v_id].size())
	{
	    for (NodeIDs_vector::const_iterator neighbor = m_node_Neighbors[node_u_id].begin(); neighbor != m_node_Neighbors[node_u_id].end(); ++neighbor)
	    {
		if (*neighbor == node_v_id)
		{
		    return false;
		}
	    }
	}
	else
	{
	    for (NodeIDs_vector::const_iterator neighbor = m_node_Neighbors[node_v_id].begin(); neighbor != m_node_Neighbors[node_v_id].end(); ++neighbor)
	    {
		if (*neighbor == node_u_id)
		{
		    return false;
		}
	    }	    
	}

	m_node_Neighbors[node_u_id].push_back(node_v_id);
	m_node_Neighbors[node_v_id].push_back(node_u_id);

	ClusterIDs_vector u_cluster_IDs = m_cluster_Mapping[node_u_id];
	ClusterIDs_vector v_cluster_IDs = m_cluster_Mapping[node_v_id];	

	for (ClusterIDs_vector::const_iterator cluster_U = u_cluster_IDs.begin(); cluster_U != u_cluster_IDs.end(); ++cluster_U)
	{
	    for (ClusterIDs_vector::const_iterator cluster_V = v_cluster_IDs.begin(); cluster_V != v_cluster_IDs.end(); ++cluster_V)
	    {
		increment_ClusterLink(*cluster_U, *cluster_V);
	    }
	}
	
	return true;
    }


    bool sNetwork::increment_ClusterLink(sInt_32 cluster_U_id, sInt_32 cluster_V_id)
    {
	if (m_cluster_Linking[cluster_U_id].find(cluster_V_id) == m_cluster_Linking[cluster_U_id].end())
	{
	    sASSERT(m_cluster_Linking[cluster_V_id].find(cluster_U_id) == m_cluster_Linking[cluster_V_id].end());

	    m_cluster_Linking[cluster_U_id].insert(ClusterLinks_map::value_type(cluster_V_id, 0));
	    m_cluster_Linking[cluster_V_id].insert(ClusterLinks_map::value_type(cluster_U_id, 0));
	}
	
	sASSERT(m_cluster_Linking[cluster_U_id][cluster_V_id] == m_cluster_Linking[cluster_V_id][cluster_U_id]);
	
	++m_cluster_Linking[cluster_U_id][cluster_V_id];
	++m_cluster_Linking[cluster_V_id][cluster_U_id];

	sInt_32 biclique_size = m_node_Clustering[cluster_U_id].size() * m_node_Clustering[cluster_V_id].size();

	if (m_cluster_Linking[cluster_U_id][cluster_V_id] == biclique_size)
	{
	    NodeIDs_vector next_cluster_node_IDs;

	    for (NodeIDs_vector::const_iterator node_U = m_node_Clustering[cluster_U_id].begin(); node_U != m_node_Clustering[cluster_U_id].end(); ++node_U)
	    {
		next_cluster_node_IDs.push_back(*node_U);
		m_cluster_Mapping[*node_U].push_back(m_node_Clustering.size());
	    }
	    for (NodeIDs_vector::const_iterator node_V = m_node_Clustering[cluster_V_id].begin(); node_V != m_node_Clustering[cluster_V_id].end(); ++node_V)
	    {
		next_cluster_node_IDs.push_back(*node_V);
		m_cluster_Mapping[*node_V].push_back(m_node_Clustering.size());		
	    }	    	    
	    m_node_Clustering.push_back(next_cluster_node_IDs);
	    m_cluster_Linking.push_back(ClusterLinks_map());
	    
	    return true;
	}

	return false;
    }
    
    
/*----------------------------------------------------------------------------*/
    
    void sNetwork::to_Screen(const sString &indent) const
    {
	to_Stream(stdout, indent);	
    }

    
    void sNetwork::to_Stream(FILE *fw, const sString &indent) const
    {
	fprintf(fw, "%sNetwork: (|clusters| = %ld, |nodes| = %ld)\n", indent.c_str(), m_node_Clustering.size(), m_cluster_Mapping.size());

	fprintf(fw, "%s%sClusters [\n", indent.c_str(), s_INDENT.c_str());	
	for (sInt_32 cluster_id = 0; cluster_id < m_node_Clustering.size(); ++cluster_id)
	{
	    fprintf(fw, "%s%s%d: { ", indent.c_str(), s2_INDENT.c_str(), cluster_id);
	    
	    for (NodeIDs_vector::const_iterator node = m_node_Clustering[cluster_id].begin(); node != m_node_Clustering[cluster_id].end(); ++node)
	    {
		fprintf(fw, "%d ", *node);
	    }
	    fprintf(fw, "}\n");	    
	}
	fprintf(fw, "%s%s]\n", indent.c_str(), s_INDENT.c_str());		

	fprintf(fw, "%s%sNodes/mapping [\n", indent.c_str(), s_INDENT.c_str());	
	for (sInt_32 node_id = 0; node_id < m_cluster_Mapping.size(); ++node_id)
	{
	    fprintf(fw, "%s%s%d: { ", indent.c_str(), s2_INDENT.c_str(), node_id);
	    
	    for (NodeIDs_vector::const_iterator cluster = m_cluster_Mapping[node_id].begin(); cluster != m_cluster_Mapping[node_id].end(); ++cluster)
	    {
		fprintf(fw, "%d ", *cluster);
	    }
	    fprintf(fw, "}\n");	    
	}
	fprintf(fw, "%s%s]\n", indent.c_str(), s_INDENT.c_str());

	fprintf(fw, "%s%sNode/Linking [\n", indent.c_str(), s_INDENT.c_str());
	for (sInt_32 node_id = 0; node_id < m_node_Neighbors.size(); ++node_id)
	{
	    fprintf(fw, "%s%s%d: { ", indent.c_str(), s2_INDENT.c_str(), node_id);
	    
	    for (NodeIDs_vector::const_iterator neighbor = m_node_Neighbors[node_id].begin(); neighbor != m_node_Neighbors[node_id].end(); ++neighbor)
	    {
		fprintf(fw, "%d ", *neighbor);
	    }
	    fprintf(fw, "}\n");	    
	}	
	fprintf(fw, "%s%s]\n", indent.c_str(), s_INDENT.c_str());	
	
	fprintf(fw, "%s%sCluster/Linking [\n", indent.c_str(), s_INDENT.c_str());
	for (sInt_32 cluster_id = 0; cluster_id < m_node_Neighbors.size(); ++cluster_id)
	{
	    fprintf(fw, "%s%s%d: { ", indent.c_str(), s2_INDENT.c_str(), cluster_id);
	    
	    for (ClusterLinks_map::const_iterator link = m_cluster_Linking[cluster_id].begin(); link != m_cluster_Linking[cluster_id].end(); ++link)
	    {
		fprintf(fw, "(%d,%d) ", link->first, link->second);
	    }
	    fprintf(fw, "}\n");	    
	}		
	fprintf(fw, "%s%s]\n", indent.c_str(), s_INDENT.c_str());		
    }
    

/*----------------------------------------------------------------------------*/

} // namespace mutEX

#include "MeshSubdivisior.h"
#include <OpenMesh\Tools\Subdivider\Uniform\CatmullClarkT.hh>
#include <OpenMesh\Tools\Subdivider\Uniform\LongestEdgeT.hh>
#include <OpenMesh\Tools\Subdivider\Uniform\LoopT.hh>
#include <OpenMesh\Tools\Subdivider\Uniform\ModifiedButterFlyT.hh>
#include <OpenMesh\Tools\Subdivider\Uniform\Sqrt3T.hh>
#include <OpenMesh\Tools\Subdivider\Uniform\Sqrt3InterpolatingSubdividerLabsikGreinerT.hh>
#include <OpenMesh\Tools\Subdivider\Adaptive\Composite\RuleInterfaceT.hh>
#include <OpenMesh\Tools\Subdivider\Adaptive\Composite\RulesT.hh>

void MeshSubdivisior::MeshSubdivisionCatmullClarkT() {
	Subdivider::Uniform::CatmullClarkT<TriMesh_ArrayKernelT<Traits>> subdivisior;
	subdivisior.attach(oMesh);
	subdivisior(1);
	subdivisior.detach();
	return;
}

void MeshSubdivisior::MeshSubdivisiorLoopT() {
	Subdivider::Uniform::LoopT<TriMesh_ArrayKernelT<Traits>> subdivisior;
	subdivisior.attach(oMesh);
	subdivisior(1);
	subdivisior.detach();
	return;
}

void MeshSubdivisior::MeshSubdivisionModifiedButterFlyT() {
	Subdivider::Uniform::ModifiedButterflyT<TriMesh_ArrayKernelT<Traits>> subdivisior;
	subdivisior.attach(oMesh);
	subdivisior(1);
	subdivisior.detach();
	return;
}

void MeshSubdivisior::MeshSubdivisionSqrt3T() {
	Subdivider::Uniform::Sqrt3T<TriMesh_ArrayKernelT<Traits>> subdivisior;
	subdivisior.attach(oMesh);
	subdivisior(1);
	subdivisior.detach();
	return;
}

void MeshSubdivisior::MeshSubdivisionSqrt3InterpolatingSubdividerLabsikGreinerT() {
	Subdivider::Uniform::InterpolatingSqrt3LGT<TriMesh_ArrayKernelT<Traits>> subdivisior;
	subdivisior.attach(oMesh);
	subdivisior(1);
	subdivisior.detach();
	return;
}
#include "map"
#include "set"
#include "llvm/IR/CFG.h"
#include "llvm/IR/InstIterator.h"
#include "llvm/IR/Instruction.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/IR/Value.h"
#include "llvm/Pass.h"
#include "llvm/Support/Debug.h"
#include <iostream>
#include <llvm/Support/raw_ostream.h>
#include <ostream>
#include <vector>

using namespace llvm;
using namespace std;

namespace {

#define DEBUG_TYPE "ica"

class ICAPass : public FunctionPass {
  public:
	static char ID;
	ICAPass() : FunctionPass(ID) {}

	bool runOnFunction(Function &f) override {
        errs()<<f.getName()<<"\n";
        return false;
    }
};
} // namespace

char ICAPass::ID = 0;
static RegisterPass<ICAPass> X("ica", // the option name -> -mba
							   "Indirect Call Analysis", // option description
							   true, // true as we don't modify the CFG
							   true);

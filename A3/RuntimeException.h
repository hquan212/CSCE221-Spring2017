/*-----------------------
-	Robert Quan	-
-	CSCE 221	-
-	PA 3		-
-			-
-----------------------*/


#ifndef RUNTIMEEXCEPTION_H_
#define RUNTIMEEXCEPTION_H_

#include <string>

class RuntimeException {// generic run-time exception
 private:
   std::string errorMsg;
 public:
   RuntimeException(const std::string& err) { errorMsg = err; }
   std::string getMessage() const { return errorMsg; }
};

inline std::ostream& operator<<(std::ostream& out, const RuntimeException& e)
{
   out << e.getMessage();
   return out;
}

#endif

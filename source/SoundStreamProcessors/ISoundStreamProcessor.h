#ifndef ISOUNDSTREAMPROCESSOR_H
#define ISOUNDSTREAMPROCESSOR_H

namespace EarsExApp
{

class ISoundStreamProcessor
{
public:
   virtual bool     Init() = 0;
   virtual wchar_t* GetName() = 0;
   virtual wchar_t* GetDescription() = 0;
   virtual void     Enable() = 0;
   virtual void     Disable() = 0;
   virtual bool     IsEnabled() = 0;
};

} // namespace EarsExApp

#endif // ISOUNDSTREAMPROCESSOR_H

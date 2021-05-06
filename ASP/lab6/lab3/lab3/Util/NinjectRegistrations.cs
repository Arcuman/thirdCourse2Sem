using Ninject.Modules;
using PhoneDictionary;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace lab3.Util
{
    public class NinjectRegistrations : NinjectModule
    {
        public override void Load()
        {
            Bind<IRepository<PhoneNote>>().To<MSSQL.PhoneRepository>(); //--для каждого требования внедрения 
            //Bind<IRepository<PhoneNote>>().To<MSSQL.PhoneRepository>(); //--для каждого требования внедрения 
            //.InTransientScope()(по умолчанию)

            //Bind<IRepository<Phone>>().To<JSON_DB.PhoneRepository>().InSingletonScope(); //Объект класса будет создан один
            //раз и будет использоваться повторно.

            //Bind<IRepository<Phone>>().To<MSSQL_DB.PhoneRepository>().InThreadScope(); //Один объект на поток.

            //Bind<IRepository<Phone>>().To<JSON_DB.PhoneRepository>().InRequestScope(); //Один объект будет на каждый web-запрос
        }
    }
}
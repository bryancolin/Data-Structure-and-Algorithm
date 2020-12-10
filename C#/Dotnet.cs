using System;

namespace C_
{
    class Dotnet
    {
        private string message;
        private string title;

        public Dotnet()
        {

        }

        public string start()
        {
            message = "dotnet new";
            return message;
        }

        public string install()
        {
            message = "dotnet restore";
            return message;
        }

        public string compile()
        {
            message = "dotnet run";
            return message;
        }

        public string Title
        {
            get { return title; }
            set { title = value; }
        }
    }
}
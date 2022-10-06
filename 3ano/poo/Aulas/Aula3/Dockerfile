FROM mcr.microsoft.com/dotnet/runtime:5.0 AS base
WORKDIR /app

FROM mcr.microsoft.com/dotnet/sdk:5.0 AS build
WORKDIR /src
COPY ["Aula3/Aula3.csproj", "Aula3/"]
RUN dotnet restore "Aula3/Aula3.csproj"
COPY . .
WORKDIR "/src/Aula3"
RUN dotnet build "Aula3.csproj" -c Release -o /app/build

FROM build AS publish
RUN dotnet publish "Aula3.csproj" -c Release -o /app/publish

FROM base AS final
WORKDIR /app
COPY --from=publish /app/publish .
ENTRYPOINT ["dotnet", "Aula3.dll"]

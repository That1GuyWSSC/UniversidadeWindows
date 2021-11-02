extern Clinica criarClinica(Clinica clinica);
extern void listarFuncionario(Funcionario funcionario);
extern void listarFuncionariosClinica(Clinica clinica);
extern void listarFuncionariosAtivosClinica(Clinica clinica);
extern void limparBuffer();
extern void freeClinicasFuncionarios(Clinica *clinicas, int numClinicas);
extern int obterIndiceClinicaPorNumero(Clinica *clinicas, int numClinicas, int numClinica);
extern Clinica inativarFuncionarioPorNumero(Clinica clinica, int numFuncionario);
extern int indiceClinicaPorNumero(Clinica *clinicas, int numClinicas, int numClinica);
extern void textoMenu();
extern void menu(Clinica *clinicas, int numClinicas, Utente *utentes, int *numUtentes, Consulta *consultas, int *numConsultas);
extern void criarUtente(Utente *utentes, int numUtentes, int indiceNovoUtente);
extern void listarUtente(Utente utente);
extern void listarUtentes(Utente *utentes, int numUtentes);
extern void listarUtentesAtivos(Utente *utentes, int numUtentes);
extern void inativarUtentePeloNumeroSNS(Utente *utentes, int numUtentes, int numSNS);
extern void criarConsulta(Consulta *consultas, int indiceConsulta, Utente *utentes, int numUtentes, Clinica *clinicas, int numClinicas);

extern void listarConsulta(Consulta consulta, Utente utente, Funcionario funcionario);
extern void listarConsultas(Consulta *consultas, int numConsultas, Utente *utentes, Clinica *clinicas);
extern void listarConsultasAtivas(Consulta *consultas, int numConsultas, Utente *utentes, Clinica *clinicas);
extern Consulta inativarConsulta(Consulta consulta);


extern int idadeFuncionario(Funcionario funcionario, int diaHoje, int mesHoje, int anoHoje);
extern void mostrarMediaIdadesPorClinica(Clinica *clinicas, int numClinicas);
extern void mostrarSomaVencimentosPorGenero(Clinica *clinicas, int numClinicas);

extern float somatorioVencimentosClinica(Clinica clinica);
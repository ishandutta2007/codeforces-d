namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Unit {
        (Controlled(Controlled H))([qs[2]],([qs[1]],qs[0]));
        X(qs[2]);
        X(qs[1]);
        (Controlled(Controlled H))([qs[2]],([qs[1]],qs[0]));
        X(qs[2]);
        X(qs[1]);
        CNOT(qs[0],qs[2]);
        CNOT(qs[0],qs[1]);
        X(qs[2]);
        X(qs[1]);
        X(qs[0]);
        H(qs[0]);
    }
}
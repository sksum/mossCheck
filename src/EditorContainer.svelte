<script>
    import Editor from './Editor.svelte'
    export let lang = "cc"; 
</script>

<div id="editors">
    <table>
        <tbody>
            <th>
                <Editor id="editorA" {lang} />
            </th>
            <th>
                <Editor id="editorB" {lang} />
            </th>
        </tbody>
    </table>
</div>

<style>
    table {
        table-layout: fixed;
        width:100%;
    }
</style>